#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define ABS(a, b) (a) > (b)? ((a)-(b)): ((b)-(a))

void ElementMerger(int arr[], int arrLength) {
  if(arrLength == 1) {
    printf("%d", arr[0]);
    return;
  }
  
  int* temp = (int*)calloc((arrLength-1), sizeof(int));
  temp[0] = ABS(arr[0], arr[1]);
  for(int i = 1; i < arrLength-1; i++) {
    temp[i] = ABS(arr[i], arr[i+1]);
  }
  
  ElementMerger(temp, arrLength-1);
  return;
}

int main(void) { 
   
  // keep this function call here
  int A[] = {5, 4, 7, 4, 1};
  int arrLength = sizeof(A) / sizeof(*A);
  ElementMerger(A, arrLength);
  return 0;
    
}