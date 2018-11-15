

COMMAND(jbe,{																	\
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
			printf("\t\tlabelpoint[%d].adress = %d\n", lb, labelpoint[lb].adress);	\
			elem += 2;}																\
			)

COMMAND(add,{																	\
			*(second + j) = 14;\
			for(int k = 0; k < 10; k++)\
				word[k] = '\0';\
			i += 4;\
			j++;\
			printf("%s\n", first + i);\
			elem ++;}																\
			)


/* *(second + j) = 24;   <-- LINE*/	
/*COMMAND(push, {printf("\t\tpush pointer is %d\n", i);
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
					*(second + j) = 3; // LINE
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
			elem += 5;}, 
			{})
*/
