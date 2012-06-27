//
//  autoreleasepool.c
//  libmemmgmt
//
//  Created by Hubert Godfroy on 27/06/12.
//  Copyright (c) 2012 Mines de Nancy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "MM_base.h"
#include "MM_autoreleasepool.h"

typedef struct _scope{
    struct _scope* SurroundingScope;
    AutoReleasePool* pool;
}Scope;

static Scope* CURRENT_SCOPE;

static Scope* newScope(){
    Scope* res = malloc(sizeof(Scope));
    return res;
}

AutoReleasePool* newAutoReleasePool(){
    AutoReleasePool* res = malloc(sizeof(AutoReleasePool));
    res->obj = NULL;
    res->next = NULL;
    Scope* newscope = newScope();
    newscope->SurroundingScope = CURRENT_SCOPE;
    newscope->pool = res;
    CURRENT_SCOPE = newscope;
    return res;
}

void autorelease(void* obj){
    AutoReleasePool* CurrentPool = CURRENT_SCOPE->pool;
    if (CurrentPool->obj == NULL) {
        CurrentPool->obj = obj;
        return; 
    }
    AutoReleasePool* next = malloc(sizeof(AutoReleasePool));
    next->next = CurrentPool->next;
    next->obj = CurrentPool->obj;
    CurrentPool->next = next;
    CurrentPool->obj = obj;
}

void drain(AutoReleasePool* pool){
    if (pool != CURRENT_SCOPE->pool) {
        printf("le pool à effacer n'est pas le pool courant\n");
        exit(EXIT_FAILURE);
    }
    AutoReleasePool* tete = pool;
    while (tete != NULL) {
        if (tete->obj != NULL) {
            release(tete->obj);
        }
        AutoReleasePool* next = tete->next;
        free(tete);
        tete = next;
    }
    Scope* surroundingScope = CURRENT_SCOPE->SurroundingScope;
    free(CURRENT_SCOPE);
    CURRENT_SCOPE = surroundingScope;
}