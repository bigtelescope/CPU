COMMAND(push_rax, PUSH_RAX, {}, 													\
								printf("push rax here!\n");							\
								regarray[REG_A] = codebuff[i + 1];					\
								i += 5;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
								printf("%d element is %ld\n", i, regarray[i]);		\
								)

COMMAND(push_rax, PUSH_RBX, {}, 													\
								printf("push rax here!\n");							\
								regarray[REG_B] = codebuff[i + 1];					\
								i += 5;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
								printf("%d element is %ld\n", i, regarray[i]);		\
								)

COMMAND(push_rax, PUSH_RCX, {}, 													\
								printf("push rax here!\n");							\
								regarray[REG_C] = codebuff[i + 1];					\
								i += 5;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %ld\n", i, regarray[i]);	\
								)

COMMAND(push_rax, PUSH_RDX, {}, 													\
								printf("push rax here!\n");							\
								regarray[REG_D] = codebuff[i + 1];					\
								i += 5;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
								printf("%d element is %ld\n", i, regarray[i]);		\
								)

COMMAND(pop_rax, POP_RAX, {},	 													\
								printf("pop rax here!\n");							\
								int top = argstack.StackTop();						\
								regarray[REG_A] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %ld\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rax, POP_RBX, {},	 													\
								printf("pop rax here!\n");							\
								int top = argstack.StackTop();						\
								regarray[REG_B] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %ld\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rax, POP_RCX, {},	 													\
								printf("pop rax here!\n");							\
								int top = argstack.StackTop();						\
								regarray[REG_C] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %ld\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rax, POP_RDX, {},	 													\
								printf("pop rax here!\n");							\
								int top = argstack.StackTop();						\
								regarray[REG_D] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %ld\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)
								

COMMAND(push, PUSH,{																\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			sscanf(arrasm + i, "%s", word);											\
			if(isalpha(*(arrasm + i)))												\
			{																		\
				if(strcmp(word, "rax") == 0)										\
				{																	\
					*(codearr + j) = PUSH_RAX;										\
					i += 4;															\
				}																	\
				if(strcmp(word, "rbx") == 0)										\
				{																	\
					*(codearr + j) = PUSH_RBX;										\
					i += 4;															\
				}																	\
				if(strcmp(word, "rcx") == 0)										\
				{																	\
					*(codearr + j) = PUSH_RCX;										\
					i += 4;															\
				}																	\
				if(strcmp(word, "rdx") == 0)										\
				{																	\
					*(codearr + j) = PUSH_RDX;										\
					i += 4;															\
				}																	\
				for(int k = 0; k < 10; k++)											\
				word[k] = '\0';														\
			}																		\
			else																	\
				*(codearr + j) = PUSH;												\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			j++;																	\
			int temp = 0;															\
			sscanf(arrasm + i, "%d", &temp);										\
			memcpy(codearr + j, &temp, sizeof(int));								\
			j += sizeof(int);														\
			i += (int)(strchr(arrasm + i, '\n') - arrasm - i) + 1; 					\
			elem += 5;}, 															\
																					\
			printf("push %d here!\n", codebuff[i + 1]);													\
			printf("pointer to a push is %d\n", i);									\
			argstack.StackPush(codebuff[i + 1]);									\
			i += 5;																	\
			argstack.StackPrint();													\
			)

COMMAND(pop, POP,{																	\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			sscanf(arrasm + i, "%s", word);											\
			if(strcmp(word, "rax") == 0)											\
			{																		\
				*(codearr + j) = POP_RAX;											\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rbx") == 0)										\
			{																		\
				*(codearr + j) = POP_RBX;											\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rcx") == 0)										\
			{																		\
				*(codearr + j) = POP_RCX;											\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rdx") == 0)										\
			{																		\
				*(codearr + j) = POP_RDX;											\
				i += 4;																\
			}																		\
			else																	\
				*(codearr + j) = POP;												\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			j++;																	\
			elem ++;}, 																\
																					\
			{																		\
			printf("pop here!\n");													\
			i++;																	\
			argstack.StackPop();}													\
		)

COMMAND(jmp, JMP,{																	\
			*(codearr + j) = JMP;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("jump here\n");													\
			printf("i = %d, command = %d\n", i, codebuff[i]);						\
			i++;																	\
			i = codebuff[i];														\
			std::cout << "Yo, i have jumped!" << std::endl;							\
			printf("i = %d, command = %d\n", i, codebuff[i]);						\
			)

COMMAND(ja, JA,{																	\
			*(codearr + j) = JA;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("ja here\n");													\
			i++;																	\
			int last = argstack.StackTop();											\
			argstack.StackPop();													\
			int penult = argstack.StackTop();										\
			argstack.StackPush(last);												\
			if(last > penult)														\
				i = codebuff[i];													\
			else																	\
				i++;																\
			std::cout << "Yo, i have jumped (ja)!" << std::endl;					\
			)

COMMAND(je, JE,{																	\
			*(codearr + j) = JE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("je here\n");													\
			i++;																	\
			int last = argstack.StackTop();											\
			argstack.StackPop();													\
			int penult = argstack.StackTop();										\
			argstack.StackPush(last);												\
			if(last == penult)														\
				i = codebuff[i];													\
			else																	\
				i++;																\
			std::cout << "Yo, i have jumped (==)!" << std::endl;					\
			)

COMMAND(jb, JB,{																	\
			*(codearr + j) = JB;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("jb here\n");													\
			i++;																	\
			int last = argstack.StackTop();											\
			argstack.StackPop();													\
			int penult = argstack.StackTop();										\
			argstack.StackPush(last);												\
			if(last < penult)														\
				i = codebuff[i];													\
			else																	\
				i++;																\
			std::cout << "Yo, i have jumped (jb)!" << std::endl;					\
			)

COMMAND(jne, JNE,{																	\
			*(codearr + j) = JNE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("jne here\n");													\
			i++;																	\
			int last = argstack.StackTop();											\
			argstack.StackPop();													\
			int penult = argstack.StackTop();										\
			argstack.StackPush(last);												\
			if(last != penult)														\
				i = codebuff[i];													\
			else																	\
				i++;																\
			std::cout << "Yo, i have jumped (!=)!" << std::endl;					\
			)

COMMAND(jbe, JBE,{																	\
			*(codearr + j) = JBE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("jbe here\n\n");													\
			i++;																	\
			int last = argstack.StackTop();											\
			argstack.StackPop();													\
			int penult = argstack.StackTop();										\
			argstack.StackPush(last);												\
			if(last <= penult )														\
			{\
				i = codebuff[i];													\
				std::cout << "Yo, i have jumped (<=)!" << std::endl;					\
			}\
			else																	\
				i++;																\
			)

COMMAND(jae, JAE,{																	\
			*(codearr + j) = JAE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("jae here\n");													\
			i++;																	\
			int last = argstack.StackTop();											\
			argstack.StackPop();													\
			int penult = argstack.StackTop();										\
			argstack.StackPush(last);												\
			if(last >= penult)														\
				i = codebuff[i];													\
			else																	\
				i++;																\
			std::cout << "Yo, i have jumped (>=)!" << std::endl;					\
			)

COMMAND(add, ADD, {																	\
			*(codearr + j) = ADD;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}, 																\
																					\
			printf("add here!\n");													\
				i ++;																\
				num1 = argstack.StackTop();											\
				argstack.StackPop();												\
				num2 = argstack.StackTop();											\
				argstack.StackPop();												\
				argstack.StackPush(num1 + num2);									\
				argstack.StackPrint();												\
			)

COMMAND(div, DIV, {																	\
			*(codearr + j) = DIV;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}, 																\
			)

COMMAND(mul, MUL, {																	\
			*(codearr + j) = MUL;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}, 																\
																					\
			printf("mul here!\n");													\
			i ++;																	\
			num1 = argstack.StackTop();												\
			argstack.StackPop();													\
			num2 = argstack.StackTop();												\
			argstack.StackPop();													\
			argstack.StackPush(num1 * num2);										\
			argstack.StackPrint();													\
			)

COMMAND(sub, SUB,{																	\
			*(codearr + j) = SUB;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}, 																\
																					\
			printf("sub here!\n");													\
			i ++;																	\
			num1 = argstack.StackTop();												\
			argstack.StackPop();													\
			num2 = argstack.StackTop();												\
			argstack.StackPop();													\
			argstack.StackPush(num2 - num1);										\
			argstack.StackPrint();													\
			)

COMMAND(out, OUT,{																	\
			*(codearr + j) = OUT;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}, 																\
																					\
			printf("out here\n");													\
			i++;																	\
			std::cout << "Answer is " << argstack.StackTop() << std::endl;			\
			argstack.StackPrint();													\
			)

COMMAND(end, END,{																	\
			*(codearr + j) = END;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}, 																\
			)

COMMAND(call, CALL,{                                    	                        \
			*(codearr + j) = CALL;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 6;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(codearr + j) = labelpoint[lb].adress;									\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}, 															\
																					\
			printf("call here\n");													\
			i++;																	\
			jumpstack.StackPush(i + 1);												\
			jumpstack.StackPrint();													\
			i = codebuff[i];														\
			std::cout << "Yo, i've done call!" << std::endl;						\
			printf("i = %d, command = %d\n", i, codebuff[i]);						\
		)

COMMAND(ret, RET,{																	\
			*(codearr + j) = RET;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i +=4;																	\
			j++;																	\
			elem++;}, 																\
																					\
		printf("ret here\n");														\
			i = jumpstack.StackTop();												\
			jumpstack.StackPop();													\
			std::cout << "Yo, i've done ret!" << std::endl;							\
			printf("i = %d, command = %d\n", i, codebuff[i]);						\
		)

COMMAND(sqrt, SQRT,{
			*(codearr + j) = SQRT;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			elem++;},																\
																					\
			printf("sqrt here!\n");													\
			i++;																	\
			int top = argstack.StackTop();											\
			top = sqrt(top);														\
			argstack.StackPop();													\
			argstack.StackPush(top);												\
			printf("yo, i made a sqrt!\n");											\

			)


