#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "head.h"

const int DEFAULT_STACK_SIZE = 8;
const int AMOUNT_OF_REGISTERS = 8;

//#define _DBG

#ifdef _DBG
#define DBG
#else
#define DBG if(0)
#endif

enum REGISTERS
{
	REG_A,
	REG_B,
	REG_C,
	REG_D,
	REG_E,
	REG_F,
	REG_G,
	REG_H
};

enum ERRS
{
	EVERYTHING_OK			= -1,
	INCORRECT_ARGUMENT		= -2,
	CANT_OPEN_FILE			= -3,
	ERROR_MEM_ALLOCATING 	= -4
};

enum COMMANDS
{
	EXIT_FROM_CODE,

	#define COMMAND(cmd, CMD, CODE, CASE) CMD,
	#include "Defines.h"
	#undef COMMAND
};

class CPU
{
private:
	char * 		codebuff;      //pointer to an array with commands
	int 		codebuffsize;  //size of codebuf[]
	Stack		argstack;      //stack with arguments
	Stack 		jumpstack;	   //stack for jmp command
	double * 	regarray;	   //array for registers (there are four members)

public:
	CPU();
	~CPU();
	int FileSize(FILE * textptr);
	char * Allocation(char * argv);
	int Execution(char * codebuff);
	double ConvertToDouble(char *);
	int ConvertToInt(char *);
};

CPU::CPU() :
	argstack			(DEFAULT_STACK_SIZE),
	jumpstack			(DEFAULT_STACK_SIZE),
	regarray			((double *)calloc(AMOUNT_OF_REGISTERS, sizeof(double)))
{
	codebuff = NULL;
	codebuffsize = 0;
}

CPU::~CPU()
{
	codebuff = NULL;
}

int CPU::FileSize(FILE * textptr)
{	
	if(!textptr)
		return INCORRECT_ARGUMENT;
	long long curroff = ftell(textptr);
	fseek(textptr, 0, SEEK_END);
	long long size = ftell(textptr);
	fseek(textptr, curroff, SEEK_SET);
	return size;
}

char * CPU::Allocation(char * argv)
{
	if(!argv)
		return NULL;

	FILE * textptr = fopen(argv, "r");
	if(!textptr)
		return NULL;

	codebuffsize = FileSize(textptr);
	codebuff = (char *)calloc(codebuffsize, sizeof(char));
	if(!codebuff)
		return NULL;

	fread(codebuff, sizeof(char), codebuffsize, textptr);///check

	return codebuff;
}

double CPU::ConvertToDouble(char * a)
{
	double one  = *(double*)a;
	return one;
}

int CPU::ConvertToInt(char *a)
{
	int two = *(int*)a;
	return two;
}

int CPU::Execution(char * codebuff)
{
	if(!codebuff)
		return INCORRECT_ARGUMENT;

	int i = 0;
	double num1 = 0;
	double num2 = 0;
	while(codebuff[i] != END)
	{
		switch(codebuff[i])
		{
			#define COMMAND(cmd, CMD, CODE, CASE) \
			case CMD:				\
			{						\
				CASE				\
				break;				\
			}					
			#include "Defines.h"
			#undef COMMAND

			case EXIT_FROM_CODE:
				printf("You went out from your code\n\n\n\n");
				exit(0);
				break;
	
			default :
				printf("\n\nUnfortunately i met undefined command:(\n\n\n");
				i++;
				break;
		}
	}
	return 0;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("Ty debil, vvedi 2 argumenta epta\n");
		return INCORRECT_ARGUMENT;
	}

	CPU one;
	one.Execution(one.Allocation(argv[1]));


	DBG printf("hi\n");
	return 0;
}
