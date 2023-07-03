#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	//about the \0 of the end of the char*
	char a[5] = "12345";
	char b[6] = "12345";
	printf("%ld\n", strlen(a));	
	
	return 0;
}