#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void addSpace(char** str, int size) {
    *str = (char *)realloc(*str, size);
}


int main() {
    char *str;

  /* Initial memory allocation */
  str = (char *) malloc(15);
  strcpy(str, "yiibai");
  printf("String = %s, Address = %p\n", str, (void*)str);

  /* Reallocating memory */
  str = (char *) realloc(str, 25);
  strcat(str, ".com");
  printf("String = %s, Address = %p\n", str, (void*)str);

  int size = 30;
  addSpace(&str, size);
  for(int i = 0; i < size; i++) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  printf("String = %s, Address = %p\n", str, (void*)str);

  free(str);
   
  return 0;

}
