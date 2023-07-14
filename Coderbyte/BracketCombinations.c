#include <stdio.h> 
#include <string.h>

void BracketHelper(int left, int right, int* count) {
    if(right==0 && left==0) {
        (*count)++;
      return;
    }

    if(left == 0) {
        BracketHelper(left, right-1, count);
    } else if(right == left) {
        BracketHelper(left-1, right, count);
    } else { //left used more than right
        BracketHelper(left, right-1, count);
        BracketHelper(left-1, right, count);
    }
    return;
}

void BracketCombinations(int num) {
  int a = 0;
  int* count = &a;  
  //printf("%d\n", *count);
  BracketHelper(num, num, count);
  // code goes here  
  printf("%d", *count);

}

int main(void) { 
   
  // keep this function call here
  BracketCombinations(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}