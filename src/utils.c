#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
   char *cmdLineCopy = (char*)malloc(2048);
   int stringNum = 0;
   strcpy(cmdLineCopy, command);
   char* token = strtok(cmdLineCopy, "' '\t\n");
   (*argv) = (char**) malloc(sizeof(char*)*1000);
   (*argv)[stringNum]=(char*)malloc(sizeof(char)*1000);

   if(token ==NULL){
      *argc =1;
      strcpy((*argv)[0],"");
      return;
   }
   
   while(token !=NULL){
	   strcpy((*argv)[stringNum], token);
	   token = strtok(NULL,"' ',\t\n");
	   stringNum = stringNum +1;
	   (*argv)[stringNum]=(char*)malloc(sizeof(char)*1000);
}


*argc= stringNum;
free(cmdLineCopy);
}
