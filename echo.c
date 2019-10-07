#include <string.h>
#include <stdio.h>
#include "echo.h"

int verificar(char in[], char cond[]){
    char *match;
    match=strstr(in,cond);
    if(match) return 1;
    return 0;
}

void cortar (char dir[], char cut[]){
    if(verificar(dir,cut)){
        size_t lent=strlen(dir);
        int j=1;
        char aux[100]="~";
        for (int i = strlen(cut); i <lent ; i++) {
            aux[j]=dir[i];
            j++;
        }
        strcpy(dir,aux);
    }
}

void printEcho(char *in, char *out) {

    unsigned long lent=strlen("echo ");
    unsigned long j=0;

    for(unsigned long i=lent; i<strlen(in); i++){
        if((in[i]!=' ')){
            out[j]=in[i];
            j++;
        }
        else {
            if(in[i+1]!=' '){
                out[j]=in[i];
                j++;
            }
        }
    }
    out[j - 1]='\0';

}
