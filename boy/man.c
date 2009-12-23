/* man.c */
#include <stdio.h>
#include "man.h"
static void man_bye(void);
static void man_init(Man *self);
static void man_class_init(ManClass *klass);
GType man_get_type(void)
{
	static GType man_type = 0;
	if(!man_type)
	{
		static const GTypeInfo man_info = 
		{
			sizeof(ManClass),
			NULL, NULL,
			(GClassInitFunc)man_class_init,
			NULL, NULL,
			sizeof(Man),0,
			(GInstanceInitFunc)man_init
		};
		man_type = g_type_register_static(BOY_TYPE, "Man", &man_info, 0);
	}
	return man_type;
}
static void man_init(Man *self)
{
	g_debug("man_init");
	self->job = "none";
	self->bye = man_bye;
}
static void man_class_init(ManClass *klass)
{
	g_debug("man_class_init");
}
Man *man_new(void)
{
	g_debug("man_new");
	Man *self;
	self = g_object_new(MAN_TYPE, 0);
	return self;
}
char* man_get_job(Man *self)
{
	return self->job;
}
void man_set_job(Man *self, char *job)
{
	self->job = job;
}
Man *man_new_with_name_age_and_job(char *name, int age, char *job)
{
	Man *self;
	self = man_new();
	boy_set_name(BOY(self), name);
	boy_set_age(BOY(self), age);
	man_set_job(self, job);
	return self;
}
static void man_bye(void)
{
	g_print("Goodbye everyone!\n");
}
void man_info(Man *self)
{
	g_print("this man's name is %s\n", BOY(self)->name);
	g_print("this man's age is %d\n", BOY(self)->age);
	g_print("this man's name is %s\n", self->parent_instance.name);
}
