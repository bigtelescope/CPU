#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "head.h"

const int DEFAULT_STACK_SIZE = 8;

enum CMDS
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

public:
	CPU();
	~CPU();
	int FileSize(FILE * textptr);
	char * Allocation(char * argv);
	int Execution(char * codebuff);
};

CPU::CPU() :
	argstack(DEFAULT_STACK_SIZE)
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
		return -1;
	long long curroff = ftell(textptr);
	fseek(textptr, 0, SEEK_END);
	long long size = ftell(textptr);
	fseek(textptr, curroff, SEEK_SET);
	return size;
}

char * CPU::Allocation(char * argv)
{
	//if(!argv)
		//return -1;
	FILE * textptr = fopen(argv, "r");
	//if(!textptr)
		//return -1;
	codebuffsize = FileSize(textptr);
	codebuff = (char *)calloc(codebuffsize, sizeof(char));
	//if(!codebuff)
		//return -1;
	fread(codebuff, sizeof(char), codebuffsize, textptr);///check

	return codebuff;
}

int CPU::Execution(char * codebuff)
{
	int i = 0;
	int num1 = 0;
	int num2 = 0;
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
	
/*			case PUSH:
				printf("push here!\n");
				printf("pointer to a push is %d\n", i);
				argstack.StackPush(codebuff[i + 1]);
				i += 5;
				argstack.StackPrint();
				break;
	
			case POP:
				printf("add here!\n");
				i ++;
				num1 = argstack.StackTop();
				argstack.StackPop();
				num2 = argstack.StackTop();
				argstack.StackPop();
				argstack.StackPush(num1 + num2);
				argstack.StackPrint();
				break;
	
			case ADD:
				printf("add here!\n");
				i ++;
				num1 = argstack.StackTop();
				argstack.StackPop();
				num2 = argstack.StackTop();
				argstack.StackPop();
				argstack.StackPush(num1 + num2);
			
				argstack.StackPrint();
				break;

			case MUL:
				printf("mul here!\n");
				i ++;
				num1 = argstack.StackTop();
				argstack.StackPop();
				num2 = argstack.StackTop();
				argstack.StackPop();
				argstack.StackPush(num1 * num2);
				argstack.StackPrint();
				break;
	
	
			case SUB:
				printf("sub here!\n");
				i ++;
				num1 = argstack.StackTop();
				argstack.StackPop();
				num2 = argstack.StackTop();
				argstack.StackPop();
				argstack.StackPush(num2 - num1);
				argstack.StackPrint();
				break;	
	
			case OUT:
				printf("out here\n");
				i++;
				std::cout << "Answer is " << argstack.StackTop() << std::endl;
				argstack.StackPrint();
				break;

			case JMP:
				printf("jump here\n");
				printf("i = %d, command = %d\n", i, codebuff[i]);
				i++;
				i = codebuff[i];
				std::cout << "Yo, i have jumped!" << std::endl;
				printf("i = %d, command = %d\n", i, codebuff[i]);
				break;
*/
			default :
				printf("default\n");
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
		return -1;
	}
	CPU one;
	one.Execution(one.Allocation(argv[1]));
	//std::cout << std::endl;
}
