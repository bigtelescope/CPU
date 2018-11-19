COMMAND(push, PUSH,{																\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			sscanf(arrasm + i, "%s", word);											\
			if(isalpha(*(arrasm + i)))												\
			{																		\
				if(strcmp(word, "rax") == 0)										\
				{																	\
					*(codearr + j) = 1;												\
					i += 4;															\
				}																	\
				if(strcmp(word, "rbx") == 0)										\
				{																	\
					*(codearr + j) = 2;												\
					i += 4;															\
				}																	\
				if(strcmp(word, "rcx") == 0)										\
				{																	\
					*(codearr + j) = 3;												\
					i += 4;															\
				}																	\
				if(strcmp(word, "rdx") == 0)										\
				{																	\
					*(codearr + j) = 4;												\
					i += 4;															\
				}																	\
				for(int k = 0; k < 10; k++)											\
				word[k] = '\0';														\
			}																		\
			else																	\
				*(codearr + j) = PUSH;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			j++;																	\
			int temp = 0;															\
			sscanf(arrasm + i, "%d", &temp);										\
			memcpy(codearr + j, &temp, sizeof(int));								\
			j += sizeof(int);														\
			i += (int)(strchr(arrasm + i, '\n') - arrasm - i) + 1; 					\
			elem += 5;}																\
			)

COMMAND(pop, POP,{																	\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			sscanf(arrasm + i, "%s", word);											\
			if(strcmp(word, "rax") == 0)											\
			{																		\
				*(codearr + j) = 6;													\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rbx") == 0)										\
			{																		\
				*(codearr + j) = 7;													\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rcx") == 0)										\
			{																		\
				*(codearr + j) = 8;													\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rdx") == 0)										\
			{																		\
				*(codearr + j) = 9;													\
				i += 4;																\
			}																		\
			else																	\
				*(codearr + j) = POP;												\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			j++;																	\
			elem ++;}																\
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
			elem += 2;}																\
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
			elem += 2;}																\
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
			elem += 2;}																\
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
			elem += 2;}																\
			)

COMMAND(jne, JBE,{																	\
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
			elem += 2;}																\
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
			elem += 2;}																\
			)

COMMAND(add, ADD, {																	\
			*(codearr + j) = ADD;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(div, DIV, {																	\
			*(codearr + j) = DIV;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(mul, MUL, {																	\
			*(codearr + j) = MUL;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(sub, SUB,{																	\
			*(codearr + j) = SUB;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(out, OUT,{																	\
			*(codearr + j) = OUT;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(end, END,{																	\
			*(codearr + j) = END;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(call, CALL,{                                    	                        \
		*(codearr + j) = CALL;														\
		for(int k = 0; k < 10; k++)													\
			word[k] = '\0';															\
		i += 6;																		\
		j++;																		\
		sscanf(arrasm + i, "%d", &lb);												\
		labelpoint[lb].number = j;													\
		*(codearr + j) = labelpoint[lb].adress;										\
		while(*(arrasm + i) != '\n')												\
			i++;																	\
		i++;																		\
		j++;																		\
		elem += 2;}																	\
		)

COMMAND(ret, RET,{																	\
		*(codearr + j) = RET;														\
		for(int k = 0; k < 10; k++)													\
			word[k] = '\0';															\
		i +=4;																		\
		j++;																		\
		elem++;}																	\
		)

