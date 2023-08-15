#include <stdio.h>

extern int x;

void printFile2();

void printFile2() {
  printf("file2 : %d\n", x);
}
