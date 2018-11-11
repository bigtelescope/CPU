#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>



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
	char * first = (char *)calloc(size1 + 1, sizeof(char));
	char * second = (char *)calloc(size1, sizeof(char));
	for(int k = 0; k < size1; k++)
		first[k] = '\0';
	if(!first)
		return -1;
	if(!second)
		return -1;
	fread(first, sizeof(char), size1, asmbuff);

	int i = 0;
	int j = 0;
	while((*(first + i) != '\0') && (i < size1 - 1))
	{
		sscanf(first + i, "%s", word);
		if(strcmp(word, "push") == 0)
		{
			*(second + j) = 1;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 5;
			j++;
			int temp = 0;
			sscanf(first + i, "%d", &temp);
			char * retval = strchr(first + i, '\n');
			int sizetemp = retval - first - i;
			printf("temp = %d\tsizetemp = %d\n", temp, sizetemp);
			memcpy(second + j, &temp, sizeof(int));
			j += sizeof(int);
			i += 1; // \n
			i += sizetemp;
			printf("pointer = %s\n", first + i);
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
		if(strcmp(word, "pop") == 0)
		{
			*(second + j) = 5;
			for(int k = 0; k < 10; k++)
				word[k] = '\0';
			i += 4;
			j++;
			sscanf(first + i, "%s", second + j);
			j += 4;
			i += 2;
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

	FILE* binout = fopen("binout.txt", "wb");
	fwrite(second, 5, sizeof(char), binout);
	fclose(binout);

}


int main(int argc, char * argv[])
{
	ASM pew;
	pew.ConvertAsm(argv [1]);
}
