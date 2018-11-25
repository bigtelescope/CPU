
/*
	Дефайны - это хорошо, но все-таки в некоторых пределах. Не надо
	ими заменять функции. Много строчные дефайны - это вообще верный 
	знак, что надо делать функцию. Дефаны - это макроподстановка. 
	Из-за них код распухает как минимум, ибо несколько байтов на вызов
	функции превращаются в двести байтов инлайн кода. И дебажить 
	дефайны сложнее, думаю, ты уже заметил :)

	Ну и АСМ - это не очень на класс тянет. Это не совсем объект. 
	Раз плюсы, не значит, что надо все плюсами покрывать.
 */

#ifndef ASM_H_
#define ASM_H_

/*
	Когда дефайны длинные, можно сразу снести на новую строчку их
	начало
 */
#define LABELSEARCH() 													\
		if(*(arrasm + i) == ':')										\
		{																\
			int number = 0;												\
			sscanf(arrasm + i + 1, "%d", &number);						\
			while(*(arrasm + i) != '\n')								\
				i++;													\
			i++;														\
			labelpoint[number].adress = elem;							\
		}

/*
	Длинная строка :)
 */
#define COMMENTS() 														\
		while(*(arrasm + i) == ';')										\
		{																\
			while(*(arrasm + i) != '\n' && *(arrasm + i + 1) != ';' && (i < asmsize - 1))	\
				i++;													\
			i++;														\
		}

const int DEFAULT_LABEL_SIZE = 10;

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

enum COMMANDS
{
	EXIT_FROM_CODE,

	#define COMMAND(cmd, CMD, CODE, CASE) CMD,
	#include "Defines.h"
	#undef COMMAND
};

/*
	Доксиген?)
	Ставишь же комменты, поясняющие суть функций и полей класса. 
	Для того его и придумывали...
 */
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

