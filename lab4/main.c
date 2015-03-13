#include <stdio.h>
#include "myCString.h"

#define PRINTOUT(x)	printf("%s: %s \n", #x, x);

#define PRINTINT(x) 	printf("%s: %d \n", #x, x);

int main()
{
	char str[100] = "Test string";
	char str2[100];

	mystrcpy(str2, str);
	PRINTOUT(str);
	PRINTOUT(str2);
	
	int a = mystrlen(str);
	int b = mystrlen(str2);
	PRINTINT(a);
	PRINTINT(b);
	
	char* str3;
	str3 = mystrcat(str, " cat");
	PRINTOUT(str3);
	
	int str4 = mystrcmp(str, str2);	
	int str5 = mystrcmp(str, str3);
	PRINTINT(str4);
	PRINTINT(str5);
	int str7 = mystrcmp(str, "Hi there");
	PRINTINT(str7);	

	char* str6;
	str6 = mystrstr(str, "string");
	PRINTOUT(str6);


	char*str8 = mystrstr(str, "Hi");
	PRINTOUT(str8);	
	return 0;
}
