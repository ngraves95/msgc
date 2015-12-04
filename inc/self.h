#ifndef SELF_H
#define SELF_H

#include "class.h"

#define object_public					\
	char * (*get_name)(struct object *);		\
	void   (*print_name)(struct object *);		\
	void   (*set_name)(struct object *, char *);	\

/*
 * Public interface to object.
 */

export_class(object);

/*
 * Static functions.
 */
constructor(object,
	    void);

#endif
