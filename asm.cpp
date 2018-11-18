#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#include "asm.h"

ASM::ASM()
{
	asmbuff = NULL;
	arrasm = NULL;
	codearr = NULL;
	asmsize = 0;
	arrasmsize = 0;
}

ASM::~ASM()
{
	asmbuff = NULL;
	arrasm = NULL;
	codearr = NULL;
}

int ASM::FileSize(FILE * textptr)
{	
	if(textptr == NULL)
		return -1;

	long long curroff = ftell(textptr);
	fseek(textptr, 0, SEEK_END);
	long long size = ftell(textptr);
	fseek(textptr, curroff, SEEK_SET);
	return size;
}

int ASM::MakeBinout(char * codearr, int j)
{
	if(!codearr)
		return 1;

	FILE* binout = fopen("binout.txt", "wb");
	if(!binout)
		return -2;
	
	fwrite(codearr, sizeof(char), j, binout);
	fclose(binout);
	return 0;
}

int ASM::CreateMem(int asmsize)
{
	labelpoint = (Label *)calloc(10, sizeof(Label));
	if(!labelpoint)
		return -3;

	arrasm = (char *)calloc(asmsize + 1, sizeof(char));// here is initial text
	if(!arrasm)
		return -3;
	for(int k = 0; k < asmsize; k++)
		arrasm[k] = '\0';

	codearr = (char *)calloc(asmsize, sizeof(char));// here is machine code
	if(!codearr)
		return -3;

	return 0;
}

int ASM::LabelAlloc(char * codearr, Label * labelpoint)
{
	printf("ORDINARY LABELS:\n");
	for(int i = 0; i < 10; i++)
	{
		printf("\n\ncell = %d, adress = %d, number = %d\n", i, labelpoint[i].adress, labelpoint[i].number);
		if(labelpoint[i].number)
			*(codearr +  labelpoint[i].number) = labelpoint[i].adress;
	}
	return 0;
}

int ASM::ConvertAsm(char * argv)
{
	asmbuff = fopen(argv, "r");
	asmsize = FileSize(asmbuff);

	char word[10];
	CreateMem(asmsize);
	fread(arrasm, sizeof(char), asmsize, asmbuff);
	fclose(asmbuff);

	int i = 0;	 //counter for a arrasm array
	int j = 0;	 //counter for a codearr array
	int lb = 0;  //counter for a label's array
	int elem = 0;//amount of elements into binout.txt
	while((*(arrasm + i) != '\0') && (i <= asmsize - 1))
	{
		LABELSEARCH()

		sscanf(arrasm + i, "%s", word);

		#define COMMAND( CMD , CODE )	\
		if (strcmp(word, #CMD) == 0)	\
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
