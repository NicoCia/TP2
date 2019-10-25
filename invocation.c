#include "invocation.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

char *punt[100];

int leer_comando(char comando[] ,char *argv[] ,char *entrada ,char *salida){
    int estado=1;
    int step=0;
    int p=0;
    int j=0;

    entrada=NULL; //redireccion entrada
    salida=NULL; //redireccion salida

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

int invocar(char argv[]){
    leer_comando(argv);

    return 0;
}
