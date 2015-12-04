#ifndef COUNTER_H
#define COUNTER_H

#include "class.h"

#define counter_public						\
	int (*get_count) (struct counter *);			\
        void (*inc) (struct counter *);

export_class(counter);
export_constructor(counter, int);

#endif
