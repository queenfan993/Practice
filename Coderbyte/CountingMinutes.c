#include <stdio.h> 
#include <string.h>
#include <stdlib.h>



void countingMinutes(char* strArr) {
  char* token = 0;
  token = strtok(strArr, ":");
  int first = atoi(token);
  
  token = strtok(NULL, "-");
  char* Str = (char*)calloc(3, sizeof(char));
  Str[0] = token[0];
  Str[1] = token[1];
  Str[2] = '\0';
  int second = atoi(Str);

  char f = token[2]; //first am pm

  token = strtok(NULL, ":");
  int third = atoi(token);
  token = strtok(NULL, ":");
  Str[0] = token[0];
  Str[1] = token[1];
  Str[2] = '\0';
  int fourth = atoi(Str);

  char s = token[2];

  //printf("%d, %d, %d, %d\n", first, second, third, fourth);

  int x = 0, y = 0;
  if(f = 'a' ) {
    x = 60*
  }


}

int main(void) { 
   
  // keep this function call here
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  
  char arr1[] = "1:00pm-11:00am";
  char arr2[] = "9:00am-10:00am";
  char arr3[] = "4,6,23,10,1,3";
  //printf("%d\n", A[0][1]);
  countingMinutes(arr1);
  return 0;
    
}
