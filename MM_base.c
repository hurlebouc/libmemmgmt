//
//  MM_base.c
//  libmemmgmt
//
//  Created by Hubert Godfroy on 23/06/12.
//  Copyright (c) 2012 Mines de Nancy. All rights reserved.
//

#include <stdio.h>
#include <Block.h>
#include <stdlib.h>
#include "MM_base.h"

typedef struct{
    info* info;
}struct_aux;

info* newMMInfo(void (* terminate)(void *)){
    info* res = malloc(sizeof(info));
    res->compteur = 1;
    res->terminate = terminate;
    return res;
}

void retain(void* this){
    struct_aux* aux = this;
    aux->info->compteur++;
}

void release(void* this){
    struct_aux* aux = this;
    aux->info->compteur--;
    if (aux->info->compteur == 0) {
        info* info = aux->info;
        info->terminate(this);
        free(info);
    }
}

