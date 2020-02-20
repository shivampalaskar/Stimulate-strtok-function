/*
 ============================================================================
 Name        : StimulateStrtok.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* stimulate_strtok(char[],char[]);

int main(void) {
	char string[40] = "Sunbeam-Hinjewadi/Pune";
	printf("string : %s\n\n",string);
	char *token = stimulate_strtok(string, "-/");
	while(token!=NULL){
		printf("%s\n",token);
		token = stimulate_strtok(NULL,"-/");
	}
	return EXIT_SUCCESS;
}

char* stimulate_strtok(char *string,char *delim){

	char *tokenStart = NULL;
	static char *tokenEnd = NULL;
	static int isStringEndReached = 0;
	char *delimStart = delim;
	int flag = 0;

	if(isStringEndReached==1)
		return NULL;

	if(string==NULL)
		string = tokenEnd;

	tokenStart = string;

	while(*string!='\0'){
		while((*delim)!='\0'){
			if(*string==(*delim)){
				flag = 1 ;
				break;
			}
			delim++;
		}
		if(flag)
			break;
		delim = delimStart;
		string++;
	}

	if(*string=='\0'){
		isStringEndReached = 1;
		return tokenStart;
	}
	else {
		tokenEnd = string + 1;
		*string = '\0';
		return tokenStart;
	}
}
