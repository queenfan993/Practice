#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int* split(char* str) {
    int length = strlen(str);
    int temp = 0;
    for(int i = 0; i < length; i++) {
      if(str[i] == ',') {
        temp = i;
        break;
      }  
    }
    char* strTemp = (char*)calloc(length, sizeof(char));
    strncpy(strTemp, str+1, temp - 1);
    int front = atoi(strTemp);
    strncpy(strTemp, str+temp+1, length - temp - 1);
    int end = atoi(strTemp);
    free(strTemp);
    int* res = (int*)malloc(2*sizeof(int));
    res[0] = front;
    res[1] = end;
    return res;
}

void TreeConstructor(char* strArr[], int arrLength) {
  int max = 0;
  //printf("front %d: %d\n", 1, (strArr[1][1] - '0'));
  for(int i = 0; i < arrLength; i++) {
    if(max < split(strArr[i])[0]) {
      max = split(strArr[i])[0];
    }
  }
  int* front = (int*)calloc(max, sizeof(int));//every nodes can appear one time  
  int* end =  (int*)calloc(max, sizeof(int));// every nodes can appear two time
  
  for(int i = 0; i < arrLength; i++) {
    front[split(strArr[i])[0]]++;
    end[split(strArr[i])[1]]++;
  }
  /*
  for(int i = 0; i < max; i++) {
    printf("front %d: %d\n", i, front[i]);
    printf("end %d: %d\n", i, end[i]);
  }
  */
  int valid = 1;
  for(int i = 0; i < max; i++) {
    if(front[i] > 1 || end[i] > 2) {
      valid = 0;
      break;
    }
  }
  if(valid){
    printf("%s", "true");
  } else {
    printf("%s", "false");
  }

}

int main(void) { 
   
  // keep this function call here
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  
  char matrix[][2] = {
  	{1, 2},
  	{2, 3}
  };

  char* A[] = { matrix[0], matrix[1] };
  int arrLength = sizeof(A) / sizeof(*A);
  //printf("%d\n", A[0][1]);
  TreeConstructor(A, arrLength);
  return 0;
    
}
