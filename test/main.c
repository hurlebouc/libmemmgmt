//
//  main.c
//  test
//
//  Created by Hubert Godfroy on 27/06/12.
//  Copyright (c) 2012 Mines de Nancy. All rights reserved.
//

#include <stdio.h>
#include "../memmgmt.h"


int main(int argc, const char * argv[]){
    AutoReleasePool* pool = newAutoReleasePool();
    
    drain(pool);
    return 0;
}

