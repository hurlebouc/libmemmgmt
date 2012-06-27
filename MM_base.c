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
    Info* info;
}struct_aux;

Info* newMMInfo(void (* terminate)(void *)){
    Info* res = malloc(sizeof(Info));
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
        Info* info = aux->info;
        info->terminate(this);
        free(info);
    }
}

