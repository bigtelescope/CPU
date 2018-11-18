#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>

typedef struct Label
{
	int 	adress;//adress for a jump
	int 	number;//adress for <adress> value in main buffer
	char * 	name;
}Label;

class ASM
{
private:
	FILE  * 	asmbuff;
	int 		size1;
	char  *		asmarr;
	int 		size2;
	char  * 	buf3;
	Label * 	labelpoint;

public:
	ASM();
	~ASM();
	int FileSize(FILE * textptr);
	int ConvertAsm(char * argv);
	
};

ASM::ASM()
{
	asmbuff = NULL;
	asmarr = NULL;
	buf3 = NULL;
	size1 = 0;
	size2 = 0;
}

ASM::~ASM()
{
	asmbuff = NULL;
	asmarr = NULL;
	buf3 = NULL;
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

int ASM::ConvertAsm(char * argv)
{
	asmbuff = fopen(argv, "r");
	size1 = FileSize(asmbuff);

	char word[10];
	labelpoint = (Label *)calloc(10, sizeof(Label));
	char * first = (char *)calloc(size1 + 1, sizeof(char));// here is initial text
	char * second = (char *)calloc(size1, sizeof(char));// here is machine code
	for(int k = 0; k < size1; k++)
		first[k] = '\0';
	if(!first)
		return -1;
	if(!second)
		return -1;
	fread(first, sizeof(char), size1, asmbuff);
	fclose(asmbuff);

	int i = 0;	 //counter for a first array
	int j = 0;	 //counter for a second array
	int lb = 0;  //counter for a label's array
	int elem = 0;//amount of elements into binout.txt
	while((*(first + i) != '\0') && (i <= size1 - 1))
	{
		if(*(first + i) == ':')
		{
			int number = 0;
			sscanf(first + i + 1, "%d", &number);
			while(*(first + i) != '\n')
				i++;
			i++;
			labelpoint[number].adress = elem;
		}
		sscanf(first + i, "%s", word);
		/*if(strcmp(word, "push") == 0)
		{
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 5;
			sscanf(first + i, "%s", word);
			if(isalpha(*(first + i)))
			{
				if(strcmp(word, "rax") == 0)
				{
					*(second + j) = 1;
					i += 4;
				}
				if(strcmp(word, "rbx") == 0)
				{
					*(second + j) = 2;
					i += 4;
				}
				if(strcmp(word, "rcx") == 0)
				{
					*(second + j) = 3;
					i += 4;
				}
				if(strcmp(word, "rdx") == 0)
				{
					*(second + j) = 4;
					i += 4;
				}
				for(int k = 0; k < 10; k++)
				word[k] = '\0';
			}
			else
				*(second + j) = 5;

			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			j++;
			int temp = 0;
			sscanf(first + i, "%d", &temp);
			memcpy(second + j, &temp, sizeof(int));
			j += sizeof(int);
			i += (int)(strchr(first + i, '\n') - first - i) + 1; // "- 1" equals "\n"
			elem += 5;
		}*/
		/*if(strcmp(word, "pop") == 0)
		{
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			sscanf(first + i, "%s", word);
			if(strcmp(word, "rax") == 0)
			{
				*(second + j) = 6;
				i += 4;
			}
			else if(strcmp(word, "rbx") == 0)
			{
				*(second + j) = 7;
				i += 4;
			}
			else if(strcmp(word, "rcx") == 0)
			{
				*(second + j) = 8;
				i += 4;
			}
			else if(strcmp(word, "rdx") == 0)
			{
				*(second + j) = 9;
				i += 4;
			}
			else
				*(second + j) = 10;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			j++;
			elem ++;
		}*/
		/*if(strcmp(word, "add") == 0)
		{
			*(second + j) = 14;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
			elem ++;
		}*/
		/*if(strcmp(word, "div") == 0)
		{
			*(second + j) = 13;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
			elem ++;
		}*/
/*		if(strcmp(word, "mul") == 0)
		{
			*(second + j) = 12;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
			elem ++;
		}*/
/*		if(strcmp(word, "sub") == 0)
		{
			*(second + j) = 11;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
			elem ++;
		}
		if(strcmp(word, "out") == 0)
		{
			*(second + j) = 15;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
			elem ++;
		}
		if(strcmp(word, "end") == 0)
		{
			*(second + j) = 16;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
			elem ++;
		}*/
		/*if(strcmp(word, "jmp") == 0)
			{
			*(second + j) = 20;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 5;
			j++;
			sscanf(first + i, "%d", &lb);
			labelpoint[lb].number = j;
			*(second + j) = labelpoint[lb].adress;
			while(*(first + i) != '\n')
				i++;
			i++;
			j++;
			elem += 2;
		}
		if(strcmp(word, "ja") == 0)
			{
			*(second + j) = 21;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			sscanf(first + i, "%d", &lb);
			labelpoint[lb].number = j;
			*(second + j) = labelpoint[lb].adress;
			while(*(first + i) != '\n')
				i++;
			i++;
			j++;
			elem += 2;
		}
		if(strcmp(word, "jb") == 0)
		{
			*(second + j) = 22;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			sscanf(first + i, "%d", &lb);
			labelpoint[lb].number = j;
			*(second + j) = labelpoint[lb].adress;
			while(*(first + i) != '\n')
				i++;
			i++;
			j++;
			elem += 2;
		}
		if(strcmp(word, "je") == 0)
		{
			*(second + j) = 22;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			sscanf(first + i, "%d", &lb);
			labelpoint[lb].number = j;
			*(second + j) = labelpoint[lb].adress;
			while(*(first + i) != '\n')
				i++;
			i++;
			j++;
			elem += 2;
		}*/
		/*if(strcmp(word, "jne") == 0)
		{
			*(second + j) = 23;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 5;
			j++;
			sscanf(first + i, "%d", &lb);
			labelpoint[lb].number = j;
			*(second + j) = labelpoint[lb].adress;
			while(*(first + i) != '\n')
				i++;
			i++;
			j++;
			elem += 2;
		}*/
		/*
		if(strcmp(word, "jbe") == 0)
		{
			*(second + j) = 24;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 5;
			j++;
			sscanf(first + i, "%d", &lb);
			*(second + j) = labelpoint[lb].adress;
			while(*(first + i) != '\n')
				i++;
			i++;
			j++;
			printf("\t\tlabelpoint[%d].adress = %d\n", lb, labelpoint[lb].adress);
			elem += 2;
		}
		*/
		/*go to a header of the asm.*/
		//#define LINE *(second + j) = CMD_##NUM;
		#define COMMAND( CMD , CODE )	\
		if (strcmp(word, #CMD) == 0)\
			CODE

		#include "Defines.h"

		#undef COMMAND


		/*if(strcmp(word, "jae") == 0)
		{
			*(second + j) = 25;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 5;
			j++;
			sscanf(first + i, "%d", &lb);
			labelpoint[lb].number = j;
			*(second + j) = labelpoint[lb].adress;
			while(*(first + i) != '\n')
				i++;
			i++;
			j++;
			elem += 2;
		}*/
/*		if (*(first+i) == '\n')
		{
			printf("\033[31m	============	\033[33mFUCK	\033[31m============\033[0m\n");
			i++;
		}*/
		printf("hello, word = '%s'\n", first + i);
	}
	printf("yo, while ended\n");

	for(int z = 0; z < 10; z++)
	{
		printf("\n\ncell = %d, adress = %d, number = %d\n", z, labelpoint[z].adress, labelpoint[z].number);
		if(labelpoint[z].number)
			*(second +  labelpoint[z].number) = labelpoint[z].adress;
	}

	FILE* binout = fopen("binout.txt", "wb");
	fwrite(second, sizeof(char), j, binout);
	fclose(binout);

	printf("\033[31m	============	\033[33mFUCK	\033[31m============\033[0m\n");

	return 0;
}


int main(int argc, char * argv[])
{
	ASM pew;
	pew.ConvertAsm(argv [1]);
}
