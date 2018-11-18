COMMAND(push,{																		\
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
				*(codearr + j) = 5;													\
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

COMMAND(pop,{																		\
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
				*(codearr + j) = 10;												\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			j++;																	\
			elem ++;}																\
		)

COMMAND(jmp,{																		\
			*(codearr + j) = 20;													\
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

COMMAND(ja,{																		\
			*(codearr + j) = 21;													\
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

COMMAND(jb,{																		\
			*(codearr + j) = 22;													\
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

COMMAND(jne,{																		\
			*(codearr + j) = 23;													\
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

COMMAND(jbe,{																		\
			*(codearr + j) = 24;													\
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

COMMAND(jae,{																		\
			*(codearr + j) = 25;													\
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

COMMAND(add, {																		\
			*(codearr + j) = 14;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(div, {																		\
			*(codearr + j) = 13;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(mul, {																		\
			*(codearr + j) = 12;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(sub,{																		\
			*(codearr + j) = 11;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(out,{																		\
			*(codearr + j) = 15;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(end,{																		\
			*(codearr + j) = 16;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			elem ++;}																\
			)

COMMAND(call,{                                    	                                \
		*(codearr + j) = 17;														\
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

COMMAND(ret,{																		\
		*(codearr + j) = 18;														\
		for(int k = 0; k < 10; k++)													\
			word[k] = '\0';															\
		i +=4;																		\
		j++;																		\
		elem++;}																	\
		)
