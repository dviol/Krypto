#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CHSIZE 37
#define SIZE 6


char path[] = "c2.txt";
char pathWortBuch[] = "PolitikHWoerter.txt";
int isIn(int, char[], char[]);
void toFileAll(FILE * out,char[][CHSIZE]);
void manualPrint(char [][CHSIZE]);
int i,j,k,l;


int main(){

	
	FILE *f = fopen(path,"r");
	FILE *deb = fopen("debug.txt","w");

	
	
	if(f == NULL){
		perror("Could not open File \n");
		return 1;
	}

	
	 char encryptedText[SIZE][CHSIZE];
	 char normText[SIZE][CHSIZE];
	

	
	for(i = 0; i< SIZE; i++){
		
		fscanf(f,"%s",encryptedText[i]);
		for(j = 0; j < CHSIZE; j++){
			encryptedText[i][j] -= 'A';
		}
		}
	
		
	for(i = 0; i< SIZE; i++){
	
		for(j = 0; j < SIZE; j++){
			
			for(k= 0; k < CHSIZE; k++){
			int temp = (encryptedText[i][k] - encryptedText[j][k]);
		//	printf("%d\n",temp);	
			normText[i][k] =  temp ;
			
			
			}
			
		}
		
		
		}
		
		

 
 
 /*
 int lengthWord = strlen(word);
 	
	for(i = 0; i<SIZE; i++){
				for(k=0;k<lengthWord;k++){
			
					
				
				printf("%c",(char) word[k] ^ normText[i][22+k]);
			
				
				
				}
			//i = XOR Array j = position im Arrays	
			printf("\n");
	}*/
			
	toFileAll(deb,normText);
	//while(1){manualPrint(normText);}
	fclose(f);
	fclose(deb);
	return 0;
	
	
}

void manualPrint(char normText[][CHSIZE]){
char word[CHSIZE];
char normed[SIZE][CHSIZE];

fflush(stdin);
printf("Enter crib:\n");
fgets(word,CHSIZE,stdin);
i = 0;
	


printf("Entered %s\n",word);

	
	int lengthWord = strlen(word);
//	int l;
	i=0;
{
      word[i] = toupper(word[i]);
      word[i] -= 'A';
      i++;
   }
	
	
	
	

		//fprintf(deb,"We are in XOR %d!\n------\n",i);
	
		
		for(j=0;j<CHSIZE-lengthWord;j++){
			for(i = 0; i< SIZE; i++){
		
				//	fprintf(deb,"Position %d, XOR %d:  ",j,i);
				for(k=0;k<lengthWord;k++){
				normed[i][k] = ((normText[i][j+k]-  word[k]) %26) + 'A' ;
			
				
				
				}
			//i = XOR Array j = position im Arrays	
			
				
			
		
			}
		for(i=0; i<SIZE;i++){
		
		printf("%s ",normed[i]);
		//printf("%s ",normed[i]);
		for(l=0; l<CHSIZE;l++){
			
		normed[i][l]= 0;
			
			}
		
		}
		printf("\n");
	

		
		
		}

		
		
			

 
}
/*
(int[SIZE][CHSIZE]) xorFile(char wort[CHSIZE],char normText[SIZE][CHSIZE],int pos){
	int normed[SIZE][CHSIZE];
	
	for(i=0; i<SIZE; i++){
		for(j=0; j<CHSIZE; j++){
		
		normed[i][j] = wort[j]^normText[i][j];
		
		}}
		
	return normed;	
	

}
*/

void toFileAll(FILE * deb,char normText[SIZE][CHSIZE]){
	char normed[SIZE][CHSIZE];
	char word[CHSIZE];
	FILE *wBuch = fopen(pathWortBuch,"r");
	
while (fscanf(wBuch, "%s", word) != EOF) {
	
	int lengthWord = strlen(word);
	i=0;
	fprintf(deb,"======\nWort ist %s\n\n",word);
	  while(word[i])
   {
      word[i] = toupper(word[i]);
      word[i] -= 'A';
      i++;
   }
	
	
	
	

		//fprintf(deb,"We are in XOR %d!\n------\n",i);
	
		
		for(j=0;j<CHSIZE-lengthWord;j++){
			for(i = 0; i< SIZE; i++){
		
				//	fprintf(deb,"Position %d, XOR %d:  ",j,i);
				for(k=0;k<lengthWord;k++){
				normed[i][k] = ((normText[i][j+k] + word[k]) % 26) + 'A' ;
			
				
				
				}
			//i = XOR Array j = position im Arrays	
			
				
			
		
			}
		for(i=0; i<SIZE;i++){
		
		fprintf(deb,"%s ",normed[i]);
		//printf("%s ",normed[i]);
		for(l=0; l<CHSIZE;l++){
			
		normed[i][l]= 0;
			
			}
		
		}
		fprintf(deb,"\n");
	

		
		
		}

		
	

}
	
	

	
	}

int isIn(int pos,  char word[], char xor[]){
	int l;
	int bigness = strlen(word);
	int temp;
		for(l=0;l<bigness;l++){
				temp = word[l] ^ xor[l+pos];
		// Intervall [65,90] Buchstaben,[48,57] Zahlen,33 = !		
		if(temp != word[l] && ((temp >= 65 && temp <= 90) ||(temp >= 48 && temp <= 57) || temp == 33  )){
					return 0;}
		else{
					
					return 1;
				}	
	
		
	}
	
	return -1;
	
	}
