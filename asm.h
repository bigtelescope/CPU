#ifndef ASM_H_
#define ASM_H_

#define LABELSEARCH() if(*(arrasm + i) == ':')						\
		{									\
			int number = 0;							\
			sscanf(arrasm + i + 1, "%d", &number);				\
			while(*(arrasm + i) != '\n')					\
				i++;							\
			i++;								\
			labelpoint[number].adress = elem;				\
		}

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

