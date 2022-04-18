#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
#include <string.h>
#define MAX_WORDS 6500

typedef struct{
    char *word;
    int length;
    int count;
} elem;

typedef struct{
    elem words[MAX_WORDS];
    int word_count;
} dictionary;

void add_count(dictionary *D, char *word){

    // check the word is in the dictionary
    int i = 0;
    int check;
    
    for(i=0;i<MAX_WORDS;i++)
    {
    	check = mstrcmp(word,D->words[i].word);   
    	if (check == 0)break;
	}
    // increase word count if the word is in the dictionary
    if (check==0)
    {
    	D->words[i].count += 1;
	}
    // add new word if the word is not in the dictionary
    else if(check!=0)
    {
    	for(i=0;i<MAX_WORDS;i++)
    	{
    		if (D->words[i].count == 0)
    		{
    			break;
			}
		}
		D->words[i].word = word;
		D->words[i].length = mstrlen(word);
		D->words[i].count = 1;
	}
	
}    

void split(dictionary *D, char *sent){
	char word[100][100];
    int i = 0;
    int j = 0;
    int k = 0;
    
    for (i = 0, j = 0, k = 0; sent[i] != '\0'; i++) {
        if (sent[i] == ' '||sent[i] == '\n') {
            if (k) {
                word[j][k] = '\0';
                j++;
            }
            k = 0;
        }
        else {
            word[j][k] = sent[i];
            k++;
        }
    }
    word[j][k] = '\0';    
    j++;     
	
	for(i=0;i<j;i++)
	{
		char* x;
        x = (char*)malloc(sizeof(char) * 100);
        mstrcpy(x, word[i]);
        add_count(D, x);
	}               
}

int main(void){
    dictionary D;
    FILE *fp;
    // char *input_file_name = "A_Little_Princess.txt";
    char *input_file_name = "Little_Lord_Fauntleroy.txt";
    int i, j;
    elem temp;

    // init dictionary
    D.word_count = 0;
    for(i=0;i<MAX_WORDS;i++)
    {
    	D.words[i].word = " ";
    	D.words[i].count = 0;
    	D.words[i].length = 0;
	}


    // open input file
    fp = fopen(input_file_name,"r");
    if(fp == NULL)
    {
    	printf("파일 열기 실패\n");
    	return 1;
	}
	
    // build dictionary
    char buf[10000];
    char res[10000];
    
    while(fscanf(fp,"%[^\n]\n",buf)==1){
    	for(i=0;i<strlen(buf);i++)
    	{
    		if(buf[i]!='\n')
    		{
    			res[i]=buf[i];
			}
		}
		printf("%s\n",res);
		split(&D, res);
		for(i=0;i<10000;i++)
		{
			res[i] = '\0';
		}
	}

	int rs;
	rs = fclose(fp);
	if (rs==-1)
	{
		printf("파일 닫기 실패\n");
		return 1;
	}
	
    // sort dictionary
    for (i = 0; i < MAX_WORDS; i++) 
	{
		for (j = 0; j < (MAX_WORDS - 1) - i; j++) 
		{
			if (D.words[j].count < D.words[j + 1].count) 
			{	
				temp = D.words[j];
				D.words[j] = D.words[j + 1];
				D.words[j + 1] = temp;
			}
		}
	}
	for(i=0;i<MAX_WORDS;i++)
	{
		D.word_count += D.words[i].count;
	}

    // print result
    printf("Novel name: %s\n",input_file_name);
    printf("--- Top 25 frequently used words list ---\n");
    for(i=0;i<25;i++)
    {
    	printf("%s  [%d]\n",D.words[i].word,D.words[i].count);
	}

    return 0;
}
