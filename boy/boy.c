/* boy.c */
#include "boy.h"
enum
{
	BOY_BORN, 

	LAST_SIGNAL
};
static gint boy_signals[LAST_SIGNAL] = {0};
static void boy_cry(void);
static void boy_born(void);
static void boy_init(Boy *boy);
static void boy_class_init(BoyClass *boyclass);

static void boy_dispose(GObject *obj)
{
	g_debug("boy_dispose");
	Boy* self = BOY(obj);
	BoyClass *klass = BOY_GET_CLASS(self);
	G_OBJECT_CLASS(g_type_class_peek_parent(klass))->dispose(obj);
}

static void boy_finalize(GObject *obj)
{
	g_debug("boy_finalize");
	Boy* self = BOY(obj);
	BoyClass *klass = BOY_GET_CLASS(self);
	G_OBJECT_CLASS(g_type_class_peek_parent(klass))->finalize(obj);
}

GType boy_get_type(void)
{
	static GType boy_type = 0;
	if(!boy_type)
	{
		static const GTypeInfo boy_info = 
		{sizeof(BoyClass),
			NULL,NULL,(GClassInitFunc)boy_class_init,
			NULL, NULL, sizeof(Boy),0,(GInstanceInitFunc)boy_init
		};
		boy_type = g_type_register_static(G_TYPE_OBJECT, "Boy", &boy_info, 0);
	}
	return boy_type;
}
static void boy_init(Boy *boy)
{
	g_debug("boy_init");
	boy->age = 0;
	boy->name = "none";
	boy->cry = boy_cry;
	g_signal_emit(boy, boy_signals[BOY_BORN], 0);
}
static void boy_class_init(BoyClass *boyclass)
{
	g_debug("boy_class_init");
	GObjectClass* gobject_class = G_OBJECT_CLASS(boyclass);
	gobject_class->dispose = boy_dispose;
	gobject_class->finalize = boy_finalize;
	boyclass->boy_born = boy_born;
	boy_signals[BOY_BORN] = g_signal_new("boy-born", BOY_TYPE, G_SIGNAL_RUN_LAST, 
			G_STRUCT_OFFSET(BoyClass, boy_born),NULL,NULL,g_cclosure_marshal_VOID__VOID,
			//NULL,NULL,NULL,g_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE, 0, NULL);
}
Boy *boy_new(void)
{
	g_debug("boy_new");
	Boy *boy;
	boy = g_object_new(BOY_TYPE, NULL);
	g_signal_emit(boy, boy_signals[BOY_BORN], 0);
	return boy;
}
int boy_get_age(Boy *boy)
{
	return boy->age;
}
void boy_set_age(Boy *boy, int age)
{
	boy->age = age;
	g_signal_emit(boy, boy_signals[BOY_BORN], 0);
}
char *boy_get_name(Boy *boy)
{
	return boy->name;
}
void boy_set_name(Boy *boy,char *name)
{
	boy->name = name;
}
Boy *boy_new_with_name(char* name)
{
	Boy *boy;
	boy = boy_new();
	boy_set_name(boy, name);
	return boy;
}
Boy *boy_new_with_age(gint age)
{
	Boy *boy;
	boy = boy_new();
	boy_set_age(boy, age);
	return boy;
}
Boy *boy_new_with_name_and_age(gchar *name, gint age)
{
	Boy *boy;
	boy = boy_new();
	boy_set_name(boy, name);
	boy_set_age(boy, age);
	return boy;
}
static void boy_cry(void)
{
	g_print("The boy is crying .....\n");
}

static void boy_born(void)
{
	g_print("MESSAGE: A boy was born.\n");
}
void boy_info(Boy *boy)
{
	g_print("The boy name is %s\n", boy->name);
	g_print("The boy age is %d\n", boy->age);
}
void boy_send_born_signal(Boy *boy)
{
	g_signal_emit(boy, boy_signals[BOY_BORN], 0);
}
