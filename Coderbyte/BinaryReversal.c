#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <math.h>

int findGreat(int num) {
	int pos = 0;
	while(num > 1) {
		num >>= 1;
		pos++;
	}
	return pos;
}

int pad(int pos) {
	if(0 < pos && pos <= 8) {
		return 8;
	} else if(8 < pos && pos <= 16) {
		return 16;
	} else if(16 < pos && pos <= 24) {
		return 24;
	} else if(24 < pos && pos <= 32) {
		return 32;
	} else {
		return 0;
	} 

}

void BinaryReversal(char * str) {
  
  int num = atoi(str);
  int great = findGreat(num);
  printf("%d\n", great);
  int padSize = pad(great);
  printf("%d\n", padSize);
  int* res = (int*)calloc(padSize, sizeof(int));

  int mask = 1;
  for(int i = 0; i < padSize; i++){
  	if(num & mask){
  		res[i] = 1;
  	}
  	num >>= 1;
  }
/*
  for(int i = padSize-1; i >= 0; i--) {
  	printf("%d", res[i]);
  }
  printf("\n");
*/
  for(int i = 0; i < padSize/2; i++) {
  	int temp = 0;
  	temp = res[i];
  	res[i] = res[padSize-1-i];
  	res[padSize-1-i] = temp;
  }
/*
  for(int i = padSize-1; i >= 0; i--) {
  	printf("%d", res[i]);
  }
  printf("\n");
*/
  int ans = 0;
  for(int i = 0; i < padSize; i++) {
  	ans += pow(2, i)*res[i]; 
  }	

  char buffer[15];
  sprintf(buffer, "%d", ans);
  printf("%s\n", buffer);

}

int main(void) { 
   
  // keep this function call here
  char a[] = "4567";
  BinaryReversal(a);
  return 0;
    
}