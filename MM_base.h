//
//  base.h
//  libmemmgmt
//
//  Created by Hubert Godfroy on 23/06/12.
//  Copyright (c) 2012 Mines de Nancy. All rights reserved.
//

#ifndef libmemmgmt_base_h
#define libmemmgmt_base_h

typedef struct _info{
    int compteur;
    void (* terminate)(void *);
}Info;

Info* newMMInfo(void (* terminate)(void *));
void retain(void*);
void release(void*);

#endif
