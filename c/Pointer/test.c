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
    char* arr1[] = {"hello", "world"};
    char str[] = "<This></is></a></test>";
    //pointer(str);

    char matrix[2][10] = {
  		"{1, 2}",
  		"{2, 3}"
  	};
  	printf("strlen:%d\n", strlen(matrix[0])); //會印出 6
  	printf("matrix[0]: %p\n", &matrix[0]); 
    printf("matrix[0][1]: %p\n", &matrix[0][1]); // 和
  	printf("matrix[1]: %p\n", &matrix[1]); // 和 matrix[0] 差 10 個字節 = 10 char 大小 
    /*
  	char* matrics[] = { matrix[0], matrix[1] };
  	printf("%s\n", matrics[0]);
  	printf("%s\n", matrics[1]);
  	*/
  	char** A = (char**)calloc(2, sizeof(char*));
  	for(int i = 0; i < 2; i++) {
  		A[i] = (char*)calloc(5, sizeof(char));
  		sprintf(A[i], "%d, %d", i, i+1);
  	}
    printf("%d\n", sizeof(int*));
  	printf("A[0]:%p\n", A[0]);
    printf("A[0][0]:%p\n", A[0][0]); 
    printf("A[0][1]:%p\n", A[0][1]);
  	printf("A[1]:%p\n", A[1]); 
	
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
