#ifndef CLASS_H
#define CLASS_H

#define PTR_SIZE sizeof((char *)"\0")

/*
 * Static macros; functions bound to a class.
 */

/*
 * Use to call.
 */
#define __static_call(class, message, ...)	\
	class##_##message(__VA_ARGS__)
#define _$(class, ...)				\
	__static_call(class, __VA_ARGS__)

/*
 * Use to declare.
 */
#define _static(class, ret, name, ...)		\
	ret class##_##name (__VA_ARGS__)
#define static(class, ...)			\
	_static(class, ##__VA_ARGS__)

/*
 * Instance macros.
 */

/*
 * Use to call.
 */
#define __call(var, message, ...) (var)->message(var, ##__VA_ARGS__)
#define _(var, ...) __call(var, __VA_ARGS__)

/*
 * Use to declare.
 */

/*
 * Declares an instance method.
 */
#define method(class, ret_type, name, ...)			\
	static ret_type name (struct class * self, ##__VA_ARGS__)

/*
 * Creates a heap-allocated object.
 */
#define constructor(class, ...)			\
	struct class * class##_new (__VA_ARGS__)

/*
 * Destroys a heap-allocated object.
 */
#define destructor(class)				\
	static void destroy(struct class * self)

#define register(method_name) this->method_name = method_name

/*
 * 'alloc'. Grabs memory for an object.
 */
#define pack(num, pack) (((num / pack) * pack) + ((num % pack) ? pack : 0))
#define alloc(class)					\
	malloc(sizeof(struct class)			\
	       + sizeof(struct class##_private))	\
	+ sizeof(struct class##_private)

#define private(class, body)				\
	struct class##_private {			\
		body					\
	} __attribute__((aligned(PTR_SIZE)));		\
	struct class##_full {				\
		body					\
		class##_public				\
		void (*destroy) (struct class *);	\
	} __attribute__((aligned(PTR_SIZE)));


#define export_class(type)				\
	struct type {					\
		type##_public				\
		void (*destroy) (struct type *);	\
	};

#define interface(body) body

/*
 * 'this' macro.
 */
#define xcat(a,b) a##b
#define concat(a, b) xcat(a,b)
#define this ((struct concat(CLASS(), _full) *) (((struct concat(CLASS(), _private) *) self) - 1))

#endif
