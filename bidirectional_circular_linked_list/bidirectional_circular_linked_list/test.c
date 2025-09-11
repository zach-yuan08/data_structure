#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

void list_test01()
{
	list_node* plist;
	list_init(&plist); // 这里是传哨兵位的地址，因为plist的指向发生改变
	list_push_back(plist, 1);
	list_push_back(plist, 2);
	list_push_back(plist, 3);
	list_push_back(plist, 4);
	list_push_back(plist, 5);
	list_print(plist);
	list_push_front(plist, 5);
	list_push_front(plist, 4);
	list_push_front(plist, 3);
	list_push_front(plist, 2);
	list_print(plist);
}

void list_test02()
{
	list_node* plist;
	list_init(&plist);
	list_push_back(plist, 1);
	list_push_back(plist, 2);
	list_push_back(plist, 3);
	list_push_back(plist, 4);
	list_print(plist);
	list_pop_back(plist);
	list_print(plist);
	list_pop_back(plist);
	list_print(plist);
	list_pop_back(plist);
	list_print(plist);
	list_pop_back(plist);
	list_print(plist);
}

void list_test03()
{
	list_node* plist;
	list_init(&plist);
	list_push_back(plist, 1);
	list_push_back(plist, 2);
	list_push_back(plist, 3);
	list_push_back(plist, 4);
	list_print(plist);
	list_pop_front(plist);
	list_print(plist);
	list_pop_front(plist);
	list_print(plist);
	list_pop_front(plist);
	list_print(plist);
}

void list_test04()
{
	list_node* plist;
	list_init(&plist);
	list_push_back(plist, 1);
	list_push_back(plist, 2);
	list_push_back(plist, 3);
	list_push_back(plist, 4);
	list_print(plist);
	list_node* pos = list_find(plist, 1);
	list_insert(pos, 22);
	list_print(plist);
	pos = list_find(plist, 22);
	list_erase(pos);
	list_print(plist);
	list_destroy(&plist);
}
int main()
{
	//list_test01();
	//list_test02();
	//list_test03();
	list_test04();
	return 0;
}