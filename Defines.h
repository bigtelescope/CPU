COMMAND(push_rax, PUSH_RAX, {}, 													\
								printf("push rax here!\n");							\
								argstack.StackPush(regarray[REG_A]);				\
								i++;												\
								DBG argstack.StackPrint();							\
								)

COMMAND(push_rbx, PUSH_RBX, {}, 													\
								printf("push rbx here!\n");							\
								argstack.StackPush(regarray[REG_B]);				\
								i++;												\
								DBG argstack.StackPrint();							\
								)

COMMAND(push_rcx, PUSH_RCX, {}, 													\
								printf("push rcx here!\n");							\
								argstack.StackPush(regarray[REG_C]);				\
								i++;												\
								DBG argstack.StackPrint();							\
								)

COMMAND(push_rdx, PUSH_RDX, {}, 													\
								printf("push rdx here!\n");							\
								argstack.StackPush(regarray[REG_D]);				\
								i++;												\
								DBG argstack.StackPrint();							\
								)

COMMAND(push_rex, PUSH_REX, {}, 													\
								printf("push rex here!\n");							\
								argstack.StackPush(regarray[REG_E]);				\
								regarray[REG_E] = 0;								\
								i++;												\
								DBG argstack.StackPrint();							\
								)
COMMAND(push_rfx, PUSH_RFX, {}, 													\
								printf("push rfx here!\n");							\
								argstack.StackPush(regarray[REG_F]);				\
								i++;												\
								DBG argstack.StackPrint();							\
								)
COMMAND(push_rgx, PUSH_RGX, {}, 													\
								DBG printf("push rgx here!\n");						\
								argstack.StackPush(regarray[REG_G]);				\
								i++;												\
								DBG argstack.StackPrint();							\
								)
COMMAND(push_rhx, PUSH_RHX, {}, 													\
								printf("push rhx here!\n");							\
								argstack.StackPush(regarray[REG_H]);				\
								i++;												\
								DBG argstack.StackPrint();							\
								)

COMMAND(pop_rax, POP_RAX, {},	 													\
								printf("pop rax here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_A] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rbx, POP_RBX, {},	 													\
								printf("pop rbx here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_B] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rcx, POP_RCX, {},	 													\
								printf("pop rcx here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_C] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rdx, POP_RDX, {},	 													\
								printf("pop rdx here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_D] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rex, POP_REX, {},	 													\
								printf("pop rex here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_E] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rfx, POP_RFX, {},	 													\
								printf("pop rfx here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_F] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rgx, POP_RGX, {},	 													\
								printf("pop rgx here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_G] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)

COMMAND(pop_rhx, POP_RHX, {},	 													\
								printf("pop rhx here!\n");							\
								double top = argstack.StackTop();					\
								regarray[REG_H] = top;								\
								argstack.StackPop();								\
								i++;												\
								for(int i = 0; i < AMOUNT_OF_REGISTERS; i++)		\
									printf("%d element is %lg\n", i, regarray[i]);	\
								argstack.StackPrint();								\
								)
								
COMMAND(push, PUSH, {																\
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
				if(strcmp(word, "rex") == 0)										\
				{																	\
					*(codearr + j) = PUSH_REX;										\
					i += 4;															\
				}																	\
				if(strcmp(word, "rfx") == 0)										\
				{																	\
					*(codearr + j) = PUSH_RFX;										\
					i += 4;															\
				}																	\
				if(strcmp(word, "rgx") == 0)										\
				{																	\
					*(codearr + j) = PUSH_RGX;										\
					i += 4;															\
				}																	\
				if(strcmp(word, "rhx") == 0)										\
				{																	\
					*(codearr + j) = PUSH_RHX;										\
					i += 4;															\
				}																	\
				for(int k = 0; k < 10; k++)											\
				word[k] = '\0';														\
				elem++;																\
				j++;																\
			}																		\
			else																	\
			{																		\
				*(codearr + j) = PUSH;												\
				for(int k = 0; k < 10; k++)											\
					word[k] = '\0';													\
				j++;																\
				double temp = 0;													\
				sscanf(arrasm + i, "%lg", &temp);									\
				memcpy(codearr + j, &temp, sizeof(double));							\
				j += sizeof(double);												\
				i += (int)(strchr(arrasm + i, '\n') - arrasm - i) + 1; 				\
				elem += 9;															\
			};},			 														\
																					\
				printf("push %lg here!\n", ConvertToDouble(&codebuff[i + 1]));		\
				printf("pointer to a push is %d\n", i);								\
				argstack.StackPush( ConvertToDouble(&codebuff[i + 1]));				\
				i += sizeof(double) + 1;											\
				argstack.StackPrint();												\
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
			else if(strcmp(word, "rex") == 0)										\
			{																		\
				*(codearr + j) = POP_REX;											\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rfx") == 0)										\
			{																		\
				*(codearr + j) = POP_RFX;											\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rgx") == 0)										\
			{																		\
				*(codearr + j) = POP_RGX;											\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rhx") == 0)										\
			{																		\
				*(codearr + j) = POP_RHX;											\
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
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j += sizeof(int);														\
			elem += sizeof(int) + 1;												\
			}, 																		\
																					\
			printf("jump here\n");													\
			printf("i = %d, command = %d\n", i, codebuff[i]);						\
			i++;																	\
			i = ConvertToInt(&codebuff[i]);											\
			std::cout << "Yo, i have jumped!" << std::endl;							\
			)

COMMAND(ja, JA,{																	\
			*(codearr + j) = JA;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j += sizeof(int);														\
			elem += 5;}, 															\
																					\
			printf("ja here\n");													\
			i++;																	\
			double last = argstack.StackTop();										\
			argstack.StackPop();													\
			double penult = argstack.StackTop();									\
			argstack.StackPush(last);												\
			if(last > penult)														\
			{																		\
				i = ConvertToInt(&codebuff[i]);										\
				std::cout << "Yo, i have jumped (>)!" << std::endl;					\
			}																		\
			else																	\
			{																		\
				i += 4;																\
				printf("without hump:(\n");											\
			}																		\
			printf("i = %d, command = %s, command = %d\n", i, codebuff + i, codebuff[i]);\
			)

COMMAND(je, JE,{																	\
			*(codearr + j) = JE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j += sizeof(int);														\
			elem += 5;}, 															\
																					\
			printf("je here\n");													\
			i ++;																	\
			double last = argstack.StackTop();										\
			argstack.StackPop();													\
			double penult = argstack.StackTop();									\
			argstack.StackPush(last);												\
			if(last == penult)														\
			{																		\
				i = ConvertToInt(&codebuff[i]);										\
				std::cout << "Yo, i have jumped (==)!" << std::endl;				\
			}																		\
			else																	\
			{																		\
				i += 4;																\
				printf("without hump:(\n");											\
			}																		\
			)

COMMAND(jb, JB,{																	\
			*(codearr + j) = JB;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j += sizeof(int);														\
			elem += 5;}, 															\
																					\
			printf("jb here\n");													\
			i ++;																	\
			double last = argstack.StackTop();										\
			argstack.StackPop();													\
			double penult = argstack.StackTop();									\
			argstack.StackPush(last);												\
			if(last < penult)														\
			{																		\
				i = ConvertToInt(&codebuff[i]);										\
				std::cout << "Yo, i have jumped (<)!" << std::endl;					\
			}																		\
			else																	\
			{																		\
				i += 4;																\
				printf("without hump:(\n");											\
			}																		\
			)

COMMAND(jne, JNE,{																	\
			*(codearr + j) = JNE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j += sizeof(int);														\
			elem += 5;}, 															\
																					\
			printf("jne here\n");													\
			i++;																	\
			double last = argstack.StackTop();										\
			argstack.StackPop();													\
			double penult = argstack.StackTop();									\
			argstack.StackPush(last);												\
			if(last != penult)														\
			{																		\
				i = ConvertToInt(&codebuff[i]);										\
				std::cout << "Yo, i have jumped (!=)!" << std::endl;				\
			}																		\
			else																	\
			{																		\
				i += 4;																\
				printf("without hump:(\n");											\
			}																		\
			)

COMMAND(jbe, JBE,{																	\
			*(codearr + j) = JBE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			j += sizeof(int);														\
			j++;																	\
			elem += 5;}, 															\
																					\
			printf("jbe here\n\n");													\
			i ++;																	\
			double last = argstack.StackTop();										\
			argstack.StackPop();													\
			double penult = argstack.StackTop();									\
			argstack.StackPush(last);												\
			if(last <= penult )														\
			{																		\
				i = ConvertToInt(&codebuff[i]);										\
				std::cout << "Yo, i have jumped (<=)!" << std::endl;				\
			}																		\
			else																	\
			{																		\
				i += 4;																\
				printf("without hump:(\n");											\
			}																		\
			)

COMMAND(jae, JAE,{																	\
			*(codearr + j) = JAE;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(arrasm + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j += sizeof(int);														\
			elem += 5;}, 															\
																					\
			printf("jae here\n");													\
			i++;																	\
			double last = argstack.StackTop();										\
			argstack.StackPop();													\
			double penult = argstack.StackTop();									\
			argstack.StackPush(last);												\
			if(last >= penult)														\
			{																		\
				i = ConvertToInt(&codebuff[i]);										\
				std::cout << "Yo, i have jumped (>=)!" << std::endl;				\
			}																		\
			else																	\
			{																		\
				i += 4;																\
				printf("without hump:(\n");											\
			}																		\
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
																					\
			printf("div here!\n");													\
			i ++;																	\
			num1 = argstack.StackTop();												\
			argstack.StackPop();													\
			num2 = argstack.StackTop();												\
			argstack.StackPop();													\
			argstack.StackPush(num2 / num1);										\
			argstack.StackPrint();													\
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
			DBG printf("out here\n");												\
			i++;																	\
			std::cout << "Answer is " << argstack.StackTop() << std::endl;			\
			DBG argstack.StackPrint();												\
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
			while(*(arrasm + i) != '\n')											\
				i++;																\
			i++;																	\
			j += sizeof(int);														\
			elem += 5;}, 															\
																					\
			printf("call here\n");													\
			i++;																	\
			jumpstack.StackPush(i + 4);												\
			jumpstack.StackPrint();													\
			i = ConvertToInt(&codebuff[i]);											\
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
			printf("ret here\n");													\
			jumpstack.StackPrint();													\
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
			double top = argstack.StackTop();										\
			top = sqrt(top);														\
			argstack.StackPop();													\
			argstack.StackPush(top);												\
			printf("yo, i made a sqrt!\n");											\
			)

COMMAND(sq, SQ,{
			*(codearr + j) = SQ;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 3;																	\
			j++;																	\
			elem++;},																\
																					\
			printf("sq here!\n");													\
			i++;																	\
			double top = argstack.StackTop();										\
			top = top * top;														\
			argstack.StackPop();													\
			argstack.StackPush(top);												\
			printf("yo, i made a sq!\n");											\
			)

COMMAND(preg, PREG,{
			*(codearr + j) = PREG;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			elem++;},																\
																					\
			printf("preg here!\n");													\
			i++;																	\
			for(int j = 0; j < AMOUNT_OF_REGISTERS; j++)							\
				printf("#%d register = %lg\n", j + 1, regarray[j]);					\
			)

COMMAND(plab, PLAB,{
			*(codearr + j) = PLAB;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			elem++;},																\
																					\
			printf("plab here!\n");													\
			i++;																	\
			for(int j = 0; j < 10; j++)												\
				printf("#%d  = %lg\n", j + 1, regarray[j]);							\
			)


