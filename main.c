#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "prompt.h"
#include "echo.h"
#include "invocation.h"

#define CLEAR "\e[1;1H\e[2J"
#define MAX 100

int main(int argc, char *argv[]) {

    char in[MAX]="\0";
    char out[MAX]="\0";
    int bandera=0;
    FILE *fp;

    if(argc<2) fp=stdin;
    else {
        fp=fopen(argv[1],"r");
        bandera=1;
    }

    while((strcmp(in,"quit\n") != 0)){
        if(bandera==0) printPrompt();                       //Bandera estará en 1 si se lee las instrucciones de un archivo
        if(fgets(in, sizeof(in), fp)==NULL) break;
        if(strcmp(in,"clr\n")==0) {                     //Comando clr, limpia la pantalla
            printf(CLEAR);
        }
        if(verificar(in,"echo")) {
            printEcho(in,out);
            puts(out);
            strcpy(out,"\0");
        }
        if(verificar(in,"cd")){
            cd();
        }
        else invocar(in);
    }

    fclose(fp);

    return 0;
}