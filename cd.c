//
// Created by nico on 25/10/19.
//

#include "cd.h"

void cd(char* in){
    if(in!=NULL){
        if(directorioValido(in)){
            chdir(in);
        }
    }
    return;
}
