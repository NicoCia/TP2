#include "invocation.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

#define END 404
#define MAX 100


int leer_comando(char comando[] ,char punt[] ,char *argv[] ,char *entrada ,char *salida){

    int estado=0;
    int step=0;
    int p=0;
    int j=0;

    entrada=NULL; //redireccion entrada
    salida=NULL; //redireccion salida

    while(estado!=END){
        switch (estado){
            case 0:
                //nombre del programa a invocar
                for(int i=0; (comando[j]!=' ')|(comando[j]!='\n') & (i<MAX); i++){
                    punt[i]=comando[j];
                    j++;
                }
                j++;
                estado++;
                break;

            case 1:
                //argumentos del programa a invocar
                while (((comando[j]!='\n')|(comando[j]!=' <')|(comando[j]!='>'))&(p<MAX)){
                    char aux[MAX]="\0";
                    for (int k = 0; comando[j]!=' ' ; k++) {
                        aux[k]=comando[j];
                        j++;
                    }
                    argv[p]=aux;
                    p++;
                }
                argv[p]=NULL;
                estado++;
                break;

            case 2:


            default:
                estado=END;
                break;

        }
    }
    /*/while (estado){
        char aux[1000]="\0";
        for (int i = 0; argv[j]!=' '; ++i) {
            if(argv[j]!='<') {
                p=5;
                i++;
            }
            if(argv[j]!='>') {
                p=6;
                i++;
            }
            aux[i]=argv[j];
            j++;
        }
        punt[p]=aux;
        p++;
    }
    punt=*/
}

int invocar(char comando[]){
    char punt[MAX]="\0";
    char *argv[MAX]={NULL};
    char *entrada;
    char *salida;

    leer_comando(comando, punt, argv, entrada, salida);

    return 0;
}
