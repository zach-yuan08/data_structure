#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void sl_test01() 
{
	sl s;
	sl_init(&s);
	sl_destroy(&s);
}

void sl_test02()
{
	sl s;
	sl_init(&s);
	sl_push_back(&s, 1);
	sl_push_back(&s, 2);
	sl_push_back(&s, 3);
	sl_push_back(&s, 4);
	sl_push_back(&s, 5);
	sl_print(&s);
	sl_destroy(&s);
}

void sl_test03()
{
	sl s;
	sl_init(&s);
	sl_push_front(&s, 1);
	sl_push_front(&s, 2);
	sl_push_front(&s, 3);
	sl_push_front(&s, 4);
	sl_push_front(&s, 5);
	sl_push_front(&s, 6);

	sl_print(&s);
	sl_destroy(&s);
}

void sl_test04()
{
	sl s;
	sl_init(&s);
	sl_push_front(&s, 1);
	sl_push_front(&s, 2);
	sl_push_front(&s, 3);
	sl_push_front(&s, 4);
	sl_push_front(&s, 5);
	sl_push_front(&s, 6);

	sl_print(&s);

	sl_pop_back(&s);
	sl_print(&s);

	sl_pop_front(&s);
	sl_print(&s);

	sl_destroy(&s);
}

void sl_test05()
{
	sl s;
	sl_init(&s);
	sl_push_back(&s, 1);
	sl_push_back(&s, 2);
	sl_push_back(&s, 4);
	sl_insert(&s, 3, 3);
	sl_print(&s);
	sl_insert(&s, 5, 5);
	sl_print(&s);
	sl_destroy(&s);
}

void sl_test06()
{
	sl s;
	sl_init(&s);
	sl_push_back(&s, 1);
	sl_push_back(&s, 2);
	sl_push_back(&s, 4);
	sl_insert(&s, 3, 3);
	sl_print(&s);
	sl_erase(&s, 1);
	sl_print(&s);
	sl_destroy(&s);
}

void sl_test07()
{
	sl s;
	sl_init(&s);
	sl_push_back(&s, 1);
	sl_push_back(&s, 2);
	sl_push_back(&s, 3);
	sl_push_back(&s, 4);
	sl_push_back(&s, 5);
	int pos = sl_find(&s, 1);
	printf("%d ", pos);
	sl_destroy(&s);
}

int main()
{
	//sl_test01();
	//sl_test02();
	//sl_test03();
	//sl_test04();
	//sl_test05();
	//sl_test06();
	sl_test07();
	return 0;
}