#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pointer(char* str) {
	printf("char* str\n");
}

void pointerToCharArray(char* str[]) {
	printf("char* str[]\n");
}

void pointerToPointer(char** str) {
	printf("char** str\n");
}



int main() {
    
    char str[] = "<This></is></a></test>";
    //pointer(str);

    char matrix[2][20] = {
  		"{1, 2}",
  		"{2, 3}"
  	};
  	/*
  	printf("%s\n", matrix[0]);
  	printf("%s\n", matrix[1]);
  	char* matrics[] = { matrix[0], matrix[1] };
  	printf("%s\n", matrics[0]);
  	printf("%s\n", matrics[1]);
  	*/
  	char** A = (char**)calloc(2, sizeof(char*));
  	for(int i = 0; i < 2; i++) {
  		A[i] = (char*)calloc(5, sizeof(char));
  		sprintf(A[i], "%d, %d", i, i+1);
  	}
  	printf("%s\n", A[0]);
  	printf("%s\n", A[1]);
	
  	pointerToCharArray(A);
  	//pointerToCharArray(matrix);
  	/*
  	char *str1 = "This is string"; //warning
  	pointer(str1);
	*/
	int a[] = {1,2,3,4,5};
	printf("a: %d\n", a);
	printf("a: %d\n", a+1);
	printf("&a: %d\n", &a+1);

    return 0;
}
