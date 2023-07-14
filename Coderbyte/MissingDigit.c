#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int* findX(char* str1, char* str2, char* str3) {
  int* res = calloc(2, sizeof(int)); 
  for(int i = 0; i < strlen(str1); i++) {
    if(str1[i] == 'x') {
      res[0] = 1;
      res[1] = i;
      return res;
    }
  }
  for(int i = 0; i < strlen(str2); i++) {
    if(str2[i] == 'x') {
      res[0] = 2;
      res[1] = i;
      return res;
    }
  }
  for(int i = 0; i < strlen(str3); i++) {
    if(str3[i] == 'x') {
      res[0] = 3;
      res[1] = i;
      return res;
    }
  }
  return res;
}

void MissingDigit(char * str) {
  int len = strlen(str);
  char* tar = calloc(len, sizeof(char));
  char* token;
  char* del = " ";
  
  strcpy(tar, str);
  //a
  token = strtok(tar, del);
  char* a = calloc(8, sizeof(char));
  strcpy(a, token);
  //operator
  token = strtok(NULL, del);
  char* op = calloc(2, sizeof(char));
  strcpy(op, token);
  //b
  token = strtok(NULL, del);
  char* b = calloc(8, sizeof(char));
  strcpy(b, token);
  // c
  token = strtok(NULL, del);
  token = strtok(NULL, del);
  char* c = calloc(8, sizeof(char));
  strcpy(c, token);
  

  char* res = calloc(2, sizeof(char));
  int temp = 0;

  findX(a, b, c);
  printf("%d, %d\n", findX(a, b, c)[0], findX(a, b, c)[1]);
  switch(findX(a, b, c)[0]) {
    //x in a 
    case 1 :
      if(op[0] == '+'){
        temp = atoi(c) - atoi(b);        
      } else if(op[0] == '-') {
        temp = atoi(c) + atoi(b);  
      } else if(op[0] == '*') {
        temp = atoi(c) / atoi(b);
      } else {
        temp = atoi(c) * atoi(b);
      } 
      sprintf(a, "%d", temp);
      printf("a: %s\n", a);
      res[0] = a[findX(a, b, c)[1]];
      break;
    //x in b
    case 2 :
      if(op[0] == '+'){
        temp = atoi(c) - atoi(a);        
      } else if(op[0] == '-') {
        temp = atoi(c) + atoi(a);  
      } else if(op[0] == '*') {
        temp = atoi(c) / atoi(a);
      } else {
        temp = atoi(c) * atoi(a);
      }
      sprintf(b, "%d", temp);
      printf("b: %s\n", a); 
      res[0] = b[findX(a, b, c)[1]];
      break;
    //x in c
    case 3 :
      if(op[0] == '+'){
        temp = atoi(a) + atoi(b);        
      } else if(op[0] == '-') {
        temp = atoi(a) - atoi(b);  
      } else if(op[0] == '*') {
        temp = atoi(a) * atoi(b);
      } else {
        temp = atoi(a) / atoi(b);
      }
      sprintf(c, "%d", temp);
      printf("c: %s\n", a);
      res[0] = c[findX(a, b, c)[1]]; 
      break;
  }

  res[1] = '\0';

  //for(int i = 0; i < )
  // code goes here  
  printf("%s", res);

}

int main(void) { 
   
  // keep this function call here
  MissingDigit(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}

