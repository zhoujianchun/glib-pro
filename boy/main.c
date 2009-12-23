#include <stdio.h>
#include "boy.h"
#include "man.h"

void shout(void)
{
	printf("Response to boy-born sigal\n");
}

int main(void)
{
	Boy *tom, *peter;
	Man *green, *brown;

	g_type_init();

	green = man_new();
	//brown = man_new();
	tom = boy_new();
	//g_signal_connect(G_OBJECT(green), "boy-born", G_CALLBACK(shout), NULL);
	//boy_set_age(BOY(green), 21);
	//g_object_unref(G_OBJECT(brown));

	/*tom = boy_new_with_name("Tom");
	tom->cry();
	boy_info(tom);
	peter = boy_new_with_name_and_age("Peter", 10);
	peter->cry();
	boy_info(peter);

	green = man_new();
	boy_set_name(BOY(green), "Green");
	boy_set_age(BOY(green), 28);
	man_set_job(green, "Doctor");
	man_info(green);
	green->bye();

	brown = man_new_with_name_age_and_job("Brown", 30, "Teacher");
	man_info(brown);
	brown->bye();*/
	//g_object_ref(G_OBJECT(tom));
	g_object_unref(G_OBJECT(tom));
	sleep(5);

	return 0;
}
