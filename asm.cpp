#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#include "asm.h"

ASM::ASM()
{
	asmbuff = NULL;
	arrasm  = NULL;
	codearr = NULL;
	asmsize 	= 0;
	arrasmsize 	= 0;
}

ASM::~ASM()
{
	free	(asmbuff);
	free	(arrasm);
	free	(codearr);
	asmsize 	= 0;
	arrasmsize 	= 0;
}

int ASM::FileSize(FILE * textptr)
{	
	if(textptr == NULL)
		return INCORRECT_ARGS;

	long long curroff = ftell(textptr);
	if(curroff < 0)
		return SIZE_DEF_ERROR;

	if(fseek(textptr, 0, SEEK_END))
		return SIZE_DEF_ERROR;

	long long size = ftell(textptr);
	if(size < 0)
		return SIZE_DEF_ERROR;

	if(fseek(textptr, curroff, SEEK_SET))
		return SIZE_DEF_ERROR;

	return size;
}

int ASM::MakeBinout(char * codearr, int j)
{
	if(!codearr)
		return INCORRECT_ARGS;

	FILE* binout = fopen("binout.txt", "wb");
	if(!binout)
		return FILE_READING_ERROR;
	
	if((fwrite(codearr, sizeof(char), j, binout)) != j)
		return FILE_WRITING_ERROR;

	fclose(binout);

	return 0;
}

int ASM::CreateMem(int asmsize)
{
	labelpoint = (Label *)calloc(DEFAULT_LABEL_SIZE, sizeof(Label));
	if(!labelpoint)
		return MEM_ALLOC_ERROR;

	// here is initial text
	arrasm = (char *)calloc(asmsize + 1, sizeof(char));
	if(!arrasm)
		return MEM_ALLOC_ERROR;

	for(int k = 0; k < asmsize; k++)
		arrasm[k] = '\0';

	// here is machine code
	codearr = (char *)calloc(asmsize, sizeof(char));
	if(!codearr)
		return MEM_ALLOC_ERROR;

	return 0;
}

int ASM::LabelAlloc(char * codearr, Label * labelpoint)
{
	printf("\nORDINARY LABELS:\n");
	for(int i = 0; i < 10; i++)
	{
		printf("\ncell = %d, adress = %d, number = %d\n", i, labelpoint[i].adress, labelpoint[i].number);
		if(labelpoint[i].number)
		{
			memcpy(codearr +  labelpoint[i].number, &(labelpoint[i].adress), sizeof(int));
			printf("good good good good %d\n\n", *(int*)(codearr +  labelpoint[i].number));
		}
	}
	return 0;
}

int ASM::ConvertAsm(char * argv)
{
	if(!argv)
		return INCORRECT_ARGS;

	asmbuff = fopen(argv, "r");
	if(!asmbuff)
		return FILE_READING_ERROR;

	asmsize = FileSize(asmbuff);

	char word[100];
	CreateMem(asmsize);
	fread(arrasm, sizeof(char), asmsize, asmbuff);
	fclose(asmbuff);

	int i = 0;	 //counter for a arrasm array
	int j = 0;	 //counter for a codearr array
	int lb = 0;  //counter for a label's array
	int elem = 0;//amount of elements into binout.txt
	while((*(arrasm + i) != '\0') && (i <= asmsize - 1))
	{
		LABELSEARCH();
		COMMENTS();	

		if((sscanf(arrasm + i, "%s", word)) < 0)
			return ARRAY_READING_ERROR;
		
		printf("word = %s\n", word);

		#define COMMAND( cmd, CMD, CODE, CASE)	\
		if (strcmp(word, #cmd) == 0)	\
			CODE

		#include "Defines.h"
		#undef COMMAND
	}
	LabelAlloc(codearr, labelpoint);

	MakeBinout(codearr, j);

	printf("\033[31m	============	\033[33mFUCK	\033[31m============\033[0m\n");
	return 0;
}


int main(int argc, char * argv[])
{
	ASM pew;
	pew.ConvertAsm(argv [1]);
}
