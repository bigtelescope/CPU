COMMAND(push,{																		\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			sscanf(first + i, "%s", word);											\
			if(isalpha(*(first + i)))												\
			{																		\
				if(strcmp(word, "rax") == 0)										\
				{																	\
					*(second + j) = 1;												\
					i += 4;															\
				}																	\
				if(strcmp(word, "rbx") == 0)										\
				{																	\
					*(second + j) = 2;												\
					i += 4;															\
				}																	\
				if(strcmp(word, "rcx") == 0)										\
				{																	\
					*(second + j) = 3;												\
					i += 4;															\
				}																	\
				if(strcmp(word, "rdx") == 0)										\
				{																	\
					*(second + j) = 4;												\
					i += 4;															\
				}																	\
				for(int k = 0; k < 10; k++)											\
				word[k] = '\0';														\
			}																		\
			else																	\
				*(second + j) = 5;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			j++;																	\
			int temp = 0;															\
			sscanf(first + i, "%d", &temp);											\
			memcpy(second + j, &temp, sizeof(int));									\
			j += sizeof(int);														\
			i += (int)(strchr(first + i, '\n') - first - i) + 1; 					\
			elem += 5;}																\
			)

COMMAND(pop,{																		\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			sscanf(first + i, "%s", word);											\
			if(strcmp(word, "rax") == 0)											\
			{																		\
				*(second + j) = 6;													\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rbx") == 0)										\
			{																		\
				*(second + j) = 7;													\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rcx") == 0)										\
			{																		\
				*(second + j) = 8;													\
				i += 4;																\
			}																		\
			else if(strcmp(word, "rdx") == 0)										\
			{																		\
				*(second + j) = 9;													\
				i += 4;																\
			}																		\
			else																	\
				*(second + j) = 10;													\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			j++;																	\
			elem ++;}																\
		)

COMMAND(jmp,{																		\
			*(second + j) = 20;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(first + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(second + j) = labelpoint[lb].adress;									\
			while(*(first + i) != '\n')												\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}																\
			)

COMMAND(ja,{																		\
			*(second + j) = 21;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(first + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(second + j) = labelpoint[lb].adress;									\
			while(*(first + i) != '\n')												\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}																\
			)

COMMAND(jb,{																		\
			*(second + j) = 22;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			sscanf(first + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(second + j) = labelpoint[lb].adress;									\
			while(*(first + i) != '\n')												\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}																\
			)

COMMAND(jne,{																		\
			*(second + j) = 23;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(first + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(second + j) = labelpoint[lb].adress;									\
			while(*(first + i) != '\n')												\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}																\
			)

COMMAND(jbe,{																		\
			*(second + j) = 24;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(first + i, "%d", &lb);											\
			*(second + j) = labelpoint[lb].adress;									\
			while(*(first + i) != '\n')												\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}																\
			)

COMMAND(jae,{																		\
			*(second + j) = 25;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 5;																	\
			j++;																	\
			sscanf(first + i, "%d", &lb);											\
			labelpoint[lb].number = j;												\
			*(second + j) = labelpoint[lb].adress;									\
			while(*(first + i) != '\n')												\
				i++;																\
			i++;																	\
			j++;																	\
			elem += 2;}																\
			)

COMMAND(add, {																		\
			*(second + j) = 14;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			printf("%s\n", first + i);												\
			elem ++;}																\
			)

COMMAND(div, {																		\
			*(second + j) = 13;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			printf("%s\n", first + i);												\
			elem ++;}																\
			)

COMMAND(mul, {																		\
			*(second + j) = 12;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			printf("%s\n", first + i);												\
			elem ++;}																\
			)

COMMAND(sub,{																		\
			*(second + j) = 11;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			printf("%s\n", first + i);												\
			elem ++;}																\
			)

COMMAND(out,{																		\
			*(second + j) = 15;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			printf("%s\n", first + i);												\
			elem ++;}																\
			)

COMMAND(end,{																		\
			*(second + j) = 16;														\
			for(int k = 0; k < 10; k++)												\
				word[k] = '\0';														\
			i += 4;																	\
			j++;																	\
			printf("%s\n", first + i);												\
			elem ++;}																\
			)


