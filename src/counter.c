#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CLASS() counter

#include "counter.h"
#include "class.h"

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

destructor(counter)
{
	free(this);
}

constructor(counter,
	    int base)
{
	struct counter * self = alloc(counter);
	if (this) {
		register(get_count);
		register(destroy);
		register(inc);
		this->count = base;
	}
	return self;
}

#ifdef CLASS
#undef CLASS
#endif
