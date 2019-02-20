#include <stdio.h>
#include <string.h>
#include "gpsparser.h"

const char dollar[2] = "$";
const char comma[2] = ",";
char *tokenDollar;
char *tokenComma;
int index = 0;
extern char collection[20][128];

void gpsparser(char raw[], char sentence[]){
  tokenDollar = strtok(raw, dollar);
  
  /* walk through other tokens */
  while( tokenDollar != NULL) {
    
    if(tokenDollar[0] == sentence[0] && tokenDollar[1] == sentence[1] 
       && tokenDollar[2] == sentence[2] && tokenDollar[3] == sentence[3]
         && tokenDollar[4] == sentence[4]){
      
      index = 0;
      tokenComma = strtok(tokenDollar, comma);
      
      while(tokenComma != NULL){
        //snprintf(collection[index], sizeof(collection[index]), "%s", tokenComma);
        strncpy(collection[index], tokenComma, sizeof(collection[index]));
        tokenComma = strtok(NULL, comma);
        index++;
      }
    }
    tokenDollar = strtok(NULL, dollar);
  }
}