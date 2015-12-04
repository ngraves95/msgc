#include "counter.h"
#include "self.h"
#include "class.h"

#include <stdio.h>

typedef struct object * object;
typedef struct counter * counter;

int main(void)
{
	object obj = _$(object, new);
	counter c = _$(counter, new, 0);

	_(c, inc);
	_(c, inc);
	_(c, inc);
	printf("%d\n", _(c, get_count));
	_(c, destroy);

	_(obj, set_name, "Nick");
	_(obj, set_name, _(obj, get_name));
	_(obj, print_name);
	_(obj, destroy);

	return 0;
}
