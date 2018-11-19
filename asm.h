#ifndef ASM_H_
#define ASM_H_

#define LABELSEARCH() if(*(arrasm + i) == ':')						\
		{															\
			int number = 0;											\
			sscanf(arrasm + i + 1, "%d", &number);					\
			while(*(arrasm + i) != '\n')							\
				i++;												\
			i++;													\
			labelpoint[number].adress = elem;						\
		}

enum CMDS
{
	EXIT_FROM_CODE, 
	
	#define COMMAND(cmd, CMD, B) CMD,
	#include "Defines.h"
	#undef COMMAND
	/*EXIT_FROM_CODE  = 0,
	PUSH_RAX        = 1,
	PUSH_RBX		= 2,
	PUSH_RCX   		= 3,
	PUSH_RDX		= 4,
	PUSH 			= 5,
	POP_RAX			= 6,
	POP_RBX 		= 7,
	POP_RCX			= 8,
	POP_RDX			= 9,
	POP 			= 10,
	SUB 			= 11,
	MUL 			= 12,
	DIV 			= 13,
	ADD 			= 14,
	OUT 			= 15,
	END 			= 16,
	JMP 			= 20,
	JA				= 21, 
	JB 				= 22,
	JE 				= 23,
	JNE  			= 24,
	JBE				= 25,
	JW 				= 26
	CALL 			= 18,
	RET 			= 19
	ADD  			= 14,
	MUL  			= 12,
	SUB  			= 11,
	POP  			= 10,
	OUT  			= 15,
	END  			= 16,
	JMP				= 20*/
};

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
	int 		asmsize;
	char  *		arrasm;
	int 		arrasmsize;
	char  * 	codearr;
	Label * 	labelpoint;

public:
	ASM();
	~ASM();
	int FileSize			(FILE * );//returns size of an input text
	int ConvertAsm			(char * argv);
	int MakeBinout			(char *, int);//makes binout.txt
	int CreateMem			(int);//calloc's for all
	int LabelAlloc  		(char * , Label *);
};

#endif

