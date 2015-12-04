#include <stdio.h>
#include <stdlib.h>

#define CLASS() counter

#include "counter.h"
#include "class.h"

static void destroy(struct counter *);

private(counter,
	int count;
	);

method(counter,
       void, inc)
{
	this->count++;
}

method(counter,
       int, get_count)
{
	return this->count;
}

static struct counter proto = {
	.get_count = get_count,
	.inc = inc,
};

constructor(counter, int base)
{
	this->count = base;
}

destructor(counter)
{
	free(this);
}



#ifdef CLASS
#undef CLASS
#endif
