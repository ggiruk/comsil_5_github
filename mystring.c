#include "mystring.h"

int mstrlen(const char *string){
    int i = 0;
    
    while(string[i]!='\0')
    {
    	i++;
	}
	return i;
}

char *mstrcpy(char *to_string, const char *from_string){
    int i = 0;
    
    while(from_string[i]!='\0'){
    	to_string[i] = from_string[i];
    	i++;
	}
	return to_string; 
}

char *mstrncpy(char *to_string, const char *from_string, int size){
    int i;
    
    for(i=0;i<size;i++){
    	to_string[i] = from_string[i];
	} 
	return to_string;
}

int mstrcmp(const char *string1, const char *string2){
    char a, b;
    while(1)
    {
        a = *string1++;
        b = *string2++;
        if (a != b)
        {
	    if (a < b) return -1;
        if (a > b) return 1; 
        }
        if (a == 0)
        {
	    break;
	}
    }
	return 0;
}

int mstrncmp(const char *string1, const char *string2, int size){
    int i;
    
    for(i=0;i<size;i++){
		if(string1[i]>string2[i])
			return 1;
		else if (string1[i]<string2[i])
			return -1;
		else continue;
	return 0;
}

char *mstrcat(char *string1, const char *string2){
    int i = 0;
    int j = 0;
    
    while(string1[i]!='\0')
    {
    	i++;
	}
	
	while(string2[j]!='\0')
	{
		string1[i+j] = string2[j];
		j++;
	}
	
	string1[i+j] = '\0';
	
	return string1;
}

char *mstrncat(char *string1, const char *string2, int size){
    int i = 0;
    int j = 0;
    
    while(string1[i]!='\0')
    {
    	i++;
	}
	
	for(j=0;j<size;j++)
	{
		string1[i+j] = string2[j];
	}
	
	string1[i+j] = '\0';
	
	return string1;
}
#include <stdio.h>
int main(void)
{
	char *s = "sexz";
	char *c = "sexy";
	printf("%d",mstrcmp(s,c));
	return 0;
}
