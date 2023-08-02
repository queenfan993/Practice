#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void addSpace(char*** str, int size) {
    *str = (char **) calloc(size, (sizeof(char*)));
}

void addBoard(char**** res, int* size) {
    (*size)++;
    *res = (char***)realloc(*res, (*size) * sizeof(char**));
}

void temp(char*** res, int* size) {
  printf("%p\n", size);
  addBoard(&res, size);
}

int main() {
  char*** res = (char***)malloc(1 * sizeof(char**));

  char** str = (char**)malloc(5 * sizeof(char*));
  for(int i = 0; i < 5; i++) {
    str[i] = (char*)malloc(6 * sizeof(char));
    for(int j = 0; j < 5; j++) {
      str[i][j] = '0'+i;
    }
    str[i][5] = '\0';
  }
  res[0] = str;
  int size = 1;
  addBoard(&res, &size);
  res[1] = str;
  //printf("%s\n", res[size-1][2]);

  printf("%p\n", &size);
  temp(res, &size);
  //addBoard(&res, &size);
  res[2] = str;
  printf("%s\n", res[size-1][2]);
  printf("%d\n", size);

}


/*
int main() {
  char **str;

  str = (char **) calloc(1, (sizeof(char*)));
  char* temp = (char*) calloc(50, sizeof(char));
  strcat(temp, ".com");
  str[0] = temp;
  addSpace(&str, 20);
  printf("String = %s, Address = %p\n", str[15], (void*)str[0]);

  str = (char **) realloc(str, 2*sizeof(char*));
  str[1] = temp;
  printf("String = %s, Address = %p\n", str[1], (void*)str[1]);


  free(str);
   
  return 0;

}
*/
