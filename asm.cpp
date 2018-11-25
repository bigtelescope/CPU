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
	asmsize = 0;
	arrasmsize = 0;
}

ASM::~ASM()
{
/*
	А вот так уже не пойдет. Просто перменные можно просто 
	занулить, а вот указатели когда - там надо памят освобождать
	предварительно. 
 */
	asmbuff = NULL;
	arrasm  = NULL;
	codearr = NULL;
}

int ASM::FileSize(FILE * textptr)
{	
	if(textptr == NULL)
		return -1;

/*
	А как же проверить значения возвращаемые?)
	ftell(), fseek() могут ошибку кидать, неприятно тогда будет,
	хрен отловишь косяк.
 */
	long long curroff = ftell(textptr);
	fseek(textptr, 0, SEEK_END);
	long long size = ftell(textptr);
	fseek(textptr, curroff, SEEK_SET);
	return size;
}

int ASM::MakeBinout(char * codearr, int j)
{
/*
	Неименованные константы...
 */
	if(!codearr)
		return 1;

	FILE* binout = fopen("binout.txt", "wb");
	if(!binout)
		return -2;
	
/*
	Проверки?)
 */
	fwrite(codearr, sizeof(char), j, binout);
	fclose(binout);
	return 0;
}

int ASM::CreateMem(int asmsize)
{
/*
	Константы...
 */
	labelpoint = (Label *)calloc(DEFAULT_LABEL_SIZE, sizeof(Label));
	if(!labelpoint)
		return -3;

/*
	И строчки длинные...
	И константы...
 */
	arrasm = (char *)calloc(asmsize + 1, sizeof(char));// here is initial text
	if(!arrasm)
		return -3;
	for(int k = 0; k < asmsize; k++)
		arrasm[k] = '\0';

/*
	Проверки радуют глаз, но строка длинная...)
 */
	codearr = (char *)calloc(asmsize, sizeof(char));// here is machine code
	if(!codearr)
		return -3;

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
			//*(codearr +  labelpoint[i].number) = labelpoint[i].adress;
			memcpy(codearr +  labelpoint[i].number, &(labelpoint[i].adress), sizeof(int));
			printf("good good good good %d\n\n", *(int*)(codearr +  labelpoint[i].number));
		}
	}
	return 0;
}

int ASM::ConvertAsm(char * argv)
{
/*
	Проверку?)
 */
	asmbuff = fopen(argv, "r");
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
/*
	Вот тут некруто. Совсем. Надо ставить точку с запятой. Иии для
	этого придумали 

	do{...}while(0)

	Воть. То есть код дефайна заключается в do{...}while(0)
 */
		LABELSEARCH()
		COMMENTS()		

/*
	Сканфы ошибки любят бросать. Прямо очень... Вроде как %s сожрет
	все, ноо я б проверил.
 */
		sscanf(arrasm + i, "%s", word);
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
