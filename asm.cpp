#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>


class ASM
{
private:
	FILE * 		asmbuff;
	int 		size1;
	char * 		asmarr;
	int 		size2;
	char * 		buf3;

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

	int i = 0;//counter for a first array
	int j = 0;//counter for a second array
	while((*(first + i) != '\0') && (i < size1 - 1))
	{
		sscanf(first + i, "%s", word);
		if(strcmp(word, "push") == 0)
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
			printf("temp = %d\tsizetemp = %d\n", temp, 
				   (int)(strchr(first + i, '\n') - first - i)); //useless
			memcpy(second + j, &temp, sizeof(int));
			j += sizeof(int);
			i += (int)(strchr(first + i, '\n') - first - i) + 1; // "- 1" equals "\n"
			printf("pointer = %s\n", first + i);//useless
		}
		if(strcmp(word, "pop") == 0)
		{
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			if()
/*			*(second + j) = 5;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
*/
		}
		if(strcmp(word, "add") == 0)
		{
			*(second + j) = 2;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
		}
		if(strcmp(word, "mul") == 0)
		{
			*(second + j) = 3;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
		}
		if(strcmp(word, "sub") == 0)
		{
			*(second + j) = 4;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
		}
		if(strcmp(word, "out") == 0)
		{
			*(second + j) = 6;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
		}
		if(strcmp(word, "end") == 0)
		{
			*(second + j) = 7;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			printf("%s\n", first + i);
		}
	}
	printf("yo, while ended\n");

	FILE* binout = fopen("binout.txt", "wb");
	fwrite(second, sizeof(char), j, binout);
	fclose(binout);

	return 0;
}


int main(int argc, char * argv[])
{
	ASM pew;
	pew.ConvertAsm(argv [1]);
}
