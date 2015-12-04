#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Declare the class.
 */
#define CLASS() object

/*
 * Public interface for object.
 */
#include "self.h"
#include "class.h"

private(object,
	char * name;
	);

method(object,
       char *, get_name)
{
	return this->name;
}

method(object,
       void, set_name, char * name)
{
	this->name = name;
}

method(object,
       void, print_name)
{
	printf("%s\n", this->name);
}

destructor(object)
{
	free(this);
}

constructor(object,
	    void)
{
	struct object * self = alloc(object);
	if (this) {
		register(get_name);
		register(set_name);
		register(print_name);
		register(destroy);
	}

	return self;
}

#ifdef CLASS
#undef CLASS
#endif
