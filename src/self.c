#include <stdio.h>
#include <stdlib.h>

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

static void destroy(struct object * self);
static struct object proto = {
	.set_name = set_name,
	.print_name = print_name,
	.get_name = get_name,
};

constructor(object,
	    void)
{
}

destructor(object)
{
	free(this);
}

#ifdef CLASS
#undef CLASS
#endif
