#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define base 10000

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

bool ArrayAdditionHelpler(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int tot = 0;

    for(int i = 0; i < numsSize - 1; i++) {
        tot += nums[i];
        for(int j = 0; j < numsSize - 1; j++) {
           if (i != j) {
              tot += nums[j];
              if (tot == nums[numsSize-1]) {
                return true;
              }
            }
        }


        for (int k = 0; k < numsSize - 1; k++) {
          if (i != k) {
            tot -= nums[k];
            if (tot == nums[numsSize-1]) {
              return true;
            }
          }
        }
      tot = 0;
    } 
    return false;
}


void ArrayAddition(char* strArr) {
  char* token = 0;
  char del[] = ",";
  int* res = (int*)calloc(50, sizeof(int));
  token = strtok(strArr, del);
  res[0] = atoi(token);
  int index = 1;
  while(1) {
    token = strtok(NULL, del);
    if(token == NULL) break;
    res[index++] = atoi(token);
  }

  if(ArrayAdditionHelpler(res, index)) {
    printf("true");
  } else {
    printf("false");
  }

  //printf("%s\n", strArr);
}

int main(void) { 
   
  // keep this function call here
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  
  char arr1[] = "5,7,16,1,2";
  char arr2[] = "3,5,-1,8,12";
  char arr3[] = "4,6,23,10,1,3";
  //printf("%d\n", A[0][1]);
  ArrayAddition(arr3);
  return 0;
    
}
