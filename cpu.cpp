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
	FILE_READING_ERROR 		= -3,
	MEM_ALLOC_ERROR			= -4,
	SIZE_DEF_ERROR 			= -5
};

/*! \brief Here's magic
	In this enum opens every macros from "Defines.h"
	and here appear numbered command:)
*/
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
	double * 	regarray;	   //array for registers (there are eight members)

public:
	CPU();
	~CPU();
	int FileSize(FILE * textptr);		// Defines a size of a file with machine code
	char * Allocation(char * argv);		// Copies information from file to an array
	int Execution(char * codebuff);		// Translation of a machine code to C-commands
	double ConvertToDouble(char *);		// Converts pointer to a char to a pointer to a double
	int ConvertToInt(char *);			// Converts pointer to a char to a pointer to an int
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
	free		(codebuff);
	free		(regarray);
	codebuffsize = 0;
	argstack.~Stack();
	jumpstack.~Stack();
}

int CPU::FileSize(FILE * textptr)
{	
	if(!textptr)
		return INCORRECT_ARGUMENT;
	long long curroff = ftell(textptr);
	if(curroff < 0)
		return FILE_READING_ERROR;

	if(fseek(textptr, 0, SEEK_END))
		return SIZE_DEF_ERROR;

	long long size = ftell(textptr);
	if(size < 0)
		return FILE_READING_ERROR;

	if(fseek(textptr, curroff, SEEK_SET))
		return SIZE_DEF_ERROR;

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
	if(codebuffsize < 0)
		return NULL;

	codebuff = (char *)calloc(codebuffsize, sizeof(char));
	if(!codebuff)
		return NULL;

	fread(codebuff, sizeof(char), codebuffsize, textptr);///check

	return codebuff;
}

double CPU::ConvertToDouble(char * a)
{
	return *(double*)a;
}

int CPU::ConvertToInt(char *a)
{
	return *(int*)a;
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
