#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define size     		50

bool HTMLElementsHelpler(char left, char token, char** res) {
	if(left != token) {
      switch(left) {
        case 'd':
          *res[0] = 'd';
          *res[1] = 'i';
          *res[2] = 'v';
          *res[3] = '\0';
          break;
        case 'i':
          *res[0] = 'i';
          *res[1] = '\0';
          break;

        case 'b':
          (*res)[0] = 'b';
          (*res)[1] = '\0';
          break;

        case 'e':
          (*res)[0] = 'e';
          (*res)[1] = 'm';
          (*res)[2] = '\0';
          break;    
        }
        return false;
    }
    return true;
}

void HTMLElements(char * str) {
  int len = strlen(str);
  //char* tar = (char*)calloc(len, sizeof(char));
  //strcpy(tar, str);
  char** stack = (char**)calloc(size, sizeof(char*));
  for(int i =0; i < size; i++) {
    stack[i]= (char*)calloc(1, sizeof(char));
  }
  int Index = 0;

  char* res = (char*)calloc(4, sizeof(char));
  char* token;

  //stack token
  char del[] = "<";
  token = strtok(str, del);
  stack[0][0] = token[0];

  while(1){
  	token = strtok(NULL, del);
  	//printf("token: %s\n", token);
    if(token == NULL)  break;
    if(token[0] == '/') {	
      if(HTMLElementsHelpler(stack[Index][0], token[1], &res)){
      	Index--;
      } else {
      	break;
      }
    } else {
      Index++;
      stack[Index][0] = token[0];
    }
  }

  // code goes here 
  if(res) {
    printf("%s", res);
  } else {
    printf("true");
  }
  free(res);
  free(token);
  free(stack);
}

int main(void) { 
   
  // keep this function call here
  char str[] = "<div>abc</div><p><em><i>test test test</i></div></p>";
  //printf("%s\n", str);
  HTMLElements(str);
  return 0;
    
}

/*
Input: "<div><div><b></b></div></p>"
Output: div

Input: "<div>abc</div><p><em><i>test test test</b></em></p>"
Output: i
*/