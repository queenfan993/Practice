#include <string.h>
#include <stdio.h>
#include <stdlib.h>




int main() {
  char std[] = "hello world";
  
  //strcpy, strncpy
  char* str = (char*) calloc(50, sizeof(char));
  strcpy(str, std);
  printf("1.strcpy: %s\n", str);
  strncpy(str + 1, std, strlen(std));
  printf("2.strncpy with position + 1: %s\n", str);
  
  //strtok
  char* token; //to capture the element sperate by delimiter 
  char delim[] = " ";
  
  token = strtok(str, delim);
  printf("3.strtok first time: %s\n", token);
  printf("4.str after strtok: %s\n", str);
  
  token = strtok(NULL, delim); 
  printf("5.strtok second time: %s\n", token);
  printf("6.str after strtok: %s\n", str); 

  //clear 
  memset(str, 0, strlen(str));
  printf("7.str after memset to 0: %s\n", str);
  //strcat
  char str1[] = "15";
  char str2[] = "20";
  strcat(str, str1);
  printf("8.str after strcat str1: %s\n", str);
  
  strcat(str, ", ");
  strcat(str, str2);
  printf("9.str after strcat str2: %s\n", str);
  
  //strncat
  memset(str, 0, strlen(str));
  printf("10.str after memset to 0: %s\n", str);
  char str3[] = "1234";
  char str4[] = "5678";
  strncat(str, str3, 3);
  printf("11.str after strncat str3: %s\n", str);
  strncat(str, str4, 4);
  printf("12.str after strncat str4: %s\n", str);
  //atoi
  int num = atoi(str1);
  printf("13atoi(str1): %d\n", num);
  //sprint
  char* temp = (char*)calloc(50, sizeof(char));
  temp[0] = 'c';
  printf("14.befor sprint: %s\n", temp);
  sprintf(temp, "%d", num);
  printf("15.sprint: %s\n", temp);


}
