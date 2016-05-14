#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CHSIZE 37
#define SIZE 6


char path[] = "c2.txt";
char pathWortBuch[] = "PolitikHWoerter.txt";
char out[] = "outPut.txt";


void manCrib(FILE *);
(int[]) encodeMinusA(char[CHSIZE]);
(int[]) encodeChar(char[CHSIZE]);

int main(int argc, char *args[]){

FILE * cipherHandle = fopen(path,"r");
FILE * wortBHandle = fopen(pathWortBuch,"r");
FILE * outPHandle = fopen(out,"w");	
char * text[3];
int encoded[CHSIZE];
int i;
for(i=0; i<3, i++){

fscanf(cipherHandle,"%s",text[i]);
encoded[i] = encodeMinA(text[i]);
	
}

manCrib(cipherHandle);


return EXIT_SUCCESS;	
}


(int []) encodeChar(char[CHSIZE] in,int minus){
	int i1;
	int temp[CHSIZE];
	for(i1 = 0; i1 < CHSIZE; i1++){
	
		temp[i1] = in[i1] - minus;
		
	}
	return temp;

}


(int[]) encodeMinusA(char[CHSIZE] in){
	
	return encodeChar(in,(int)'A');
	
}

void manCrib(FILE * in){
	
	
	
	while(1){
		
		
		
		
		
		}
	
	
}


