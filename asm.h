#ifndef ASM_H_
#define ASM_H_

/*! \brief Searching labels in asm code
	This macros have to find every label in code and to alllocate it
	in special array of structures
*/
#define LABELSEARCH() do{												\
		if(*(arrasm + i) == ':')										\
		{																\
			int number = 0;												\
			sscanf(arrasm + i + 1, "%d", &number);						\
			while(*(arrasm + i) != '\n')								\
				i++;													\
			i++;														\
			labelpoint[number].adress = elem;							\
		}}																\
		while(0)

/*! \brief Reading comments in code
	This one allows to compiler to ignore comments in code
*/
#define COMMENTS() do{ 																	\
		while(*(arrasm + i) == ';')														\
		{																				\
		while(*(arrasm + i) != '\n' && *(arrasm + i + 1) != ';' && (i < asmsize - 1))	\
			i++;																		\
		i++;																			\
		}}																				\
		while(0)

const int DEFAULT_LABEL_SIZE = 10;

// Enum for errors constants
enum ERRORS
{
	INCORRECT_ARGS 		= -1,
	SIZE_DEF_ERROR 		= -2,
	FILE_READING_ERROR 	= -3,
	FILE_WRITING_ERROR	= -4,
	ARRAY_READING_ERROR = -5,
	MEM_ALLOC_ERROR		= -6	
};

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

/*! \brief Struct for work with labels*/
typedef struct Label
{
	int 	adress;//adress for a jump
	int 	number;//adress for <adress> value in main buffer
	char * 	name;
}Label;

class ASM
{
private:
	FILE  * 	asmbuff;		// Pointer to a file with asm
	int 		asmsize;		// Size of file asmbuff points to
	char  *		arrasm;			// Pointer to an array that keeps asm code
	int 		arrasmsize;		// Size of an array with asm code
	char  * 	codearr;		// Pointer to an array with machine code
	Label * 	labelpoint;		// Pointer to an array of struct "Label"

public:
	ASM();
	~ASM();
	int FileSize			(FILE * );				// Returns size of an input text
	int ConvertAsm			(char * argv);			// Converts an asm code to a machine code
	int MakeBinout			(char *, int);			// Makes "binout.txt" with machine code
	int CreateMem			(int);					// Calloc's for all
	int LabelAlloc  		(char * , Label *);		// Allocates labels to an array with asm code
};

#endif
