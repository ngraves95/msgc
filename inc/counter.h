#ifndef COUNTER_H
#define COUNTER_H


#include "class.h"

#define counter_public						\
	int (*get_count) (struct counter *);			\
        void (*inc) (struct counter *);

constructor(counter,
	    int);

export_class(counter);

#endif
