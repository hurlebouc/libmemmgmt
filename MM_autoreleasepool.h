//
//  autoreleasepool.h
//  libmemmgmt
//
//  Created by Hubert Godfroy on 27/06/12.
//  Copyright (c) 2012 Mines de Nancy. All rights reserved.
//

#ifndef libmemmgmt_autoreleasepool_h
#define libmemmgmt_autoreleasepool_h

typedef struct _autoreleasepool{
    void* obj;
    struct _autoreleasepool* next;
}AutoReleasePool;

AutoReleasePool* newAutoPeleasePool();
void drain(AutoReleasePool*);
void autorelease(void*);

#endif
