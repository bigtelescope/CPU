#include <iostream>
#include <cstdio>
#include <cstdlib>



class CPU
{
private:
	char * 		asmbuff;
	int 		size1;
	char * 		buf2;
	int 		size2;
	char * 		buf3;

public:
	CPU();
	~CPU();
	int FileSize(FILE * textptr);
	int ConvertAsm(char * argv);
	
};

CPU::CPU()
{
	asmbuff = NULL;
	buf2 = NULL;
	buf3 = NULL;
}

CPU::~CPU()
{
	asmbuff = NULL;
	buf2 = NULL;
	buf3 = NULL;
}

int CPU::FileSize(FILE * textptr)
{	
	if(textptr == NULL)
	{
		//	errno = EINVAL;
		//perror("Error of file reading");
		return -1;
	}
	long long curroff = ftell(textptr);
	fseek(textptr, 0, SEEK_END);
	long long size = ftell(textptr);
	fseek(textptr, curroff, SEEK_SET);
	return size;
}

int CPU::ConvertAsm(char * argv)
{
	//проверка аргв???
	FILE * textptr = fopen(argv, "r");
	size1 = FileSize(textptr);

	asmbuff = (char *)calloc(size1, sizeof(char));

	fread(asmbuff, sizeof(char), size1, textptr);

	
}

int main(int argc, char * argv[])
{
	CPU cpu;
	//cpu.ConvertAsm(argv[1]);
	//std::cout << std::endl;
}

