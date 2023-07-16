#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define size      10000

void helpler(char* str, int* nums, int* numsSize) {
    char* token = 0;
    char del[] = ", ";
    char* tar = (char*)calloc(strlen(str) + 1, sizeof(char));
    strcpy(tar, str);
    *numsSize = 1;
    token = strtok(tar, del);
    
    if(token != NULL) {

      token[0] = token[1];
      token[1] = '\0';
      nums[0] = atoi(token);
      
      while(1) {
        token = strtok(NULL, del);
        if(token != NULL) {
          nums[++(*numsSize)-1] = atoi(token);
        } else {
          break;
        }
      }    
    } else {
      *numsSize = 0;
    }
    free(tar);
}



void ArrayMatching(char * strArr[], int arrLength) {
  
  int str1[size] = {0};
  int len1 = 0;
  helpler(strArr[0], str1, &len1);

  int str2[size] = {0};
  int len2 = 0;
  helpler(strArr[1], str2, &len2);


  char res[size] = {0};
  int index = 0;
  int i = 0;
  char* temp = (char*)calloc(size, sizeof(char));
  if(len1 >= len2) {
    while(i < len1) {
      str1[i]  += str2[i];
      sprintf(temp, "%d-", str1[i++]);
      strcat(res, temp);
      index += 2;
    }
  } else {
    while(i < len2) {
      str2[i]  += str1[i];
      sprintf(temp, "%d-", str2[i++]);
      strcat(res, temp);
    }
  }
  res[strlen(res)-1] = '\0';

  // code goes here  
  printf("%s", res);

}

int main(void) { 
  char matrix[][100] = {
    "[1, 2, 5, 6, 50]",
    "[5, 2, 8, 11111, 60, 70, 80, 90, 100, 101]"
  };
  char* A[] = { matrix[0], matrix[1]};
  // keep this function call here
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  ArrayMatching(A, arrLength);
  return 0;
    
}