#define _CRT_SECURE_NO_WARNINGS 1
#include"single_list.h"

//void creat_single_list()
//{
//	// 这里为什么是slt_node*类型
//	// node1 是指向结点的指针，结点都是动态申请来的 
//	slt_node* node1 = (slt_node*)malloc(sizeof(slt_node)); 
//	node1->data = 1;
//	slt_node* node2 = (slt_node*)malloc(sizeof(slt_node));
//	node2->data = 2;
//	slt_node* node3 = (slt_node*)malloc(sizeof(slt_node));
//	node3->data = 3;
//	slt_node* node4 = (slt_node*)malloc(sizeof(slt_node));
//	node4->data = 4;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	slt_node* plist = node1;
//	slt_print(plist);
//}

void slt_test01()
{
	slt_node* node1 = NULL;
	slt_push_back(&node1, 1);
	slt_print(node1);
	slt_push_back(&node1, 2);
	slt_push_back(&node1, 3);
	slt_print(node1);
	slt_push_front(&node1, 0);
	slt_print(node1);
	slt_pop_back(&node1);
	slt_print(node1);
	slt_pop_front(&node1);
	slt_print(node1);
	slt_pop_front(&node1);
	slt_pop_front(&node1);
	slt_print(node1);
}

void slt_test02()
{
	slt_node* plist = NULL;
	slt_push_back(&plist, 1);
	slt_push_back(&plist, 2);
	slt_push_back(&plist, 3);
	slt_push_back(&plist, 4);
	slt_push_back(&plist, 5);
	slt_print(plist);
	slt_node* find = slt_find(plist, 3);
	slt_print(find);
}

void slt_test03()
{
	slt_node* plist = NULL;
	slt_push_back(&plist, 1);
	slt_push_back(&plist, 2);
	slt_push_back(&plist, 3);
	slt_push_back(&plist, 4);
	slt_push_back(&plist, 5);
	slt_print(plist);
	//slt_insert(&plist, 3, 0);
	slt_print(plist);
}

void slt_test04()
{
	slt_node* plist = NULL;
	slt_push_back(&plist, 1);
	slt_push_back(&plist, 2);
	slt_push_back(&plist, 3);
	slt_push_back(&plist, 4);
	slt_push_back(&plist, 5);
	slt_print(plist);
	slt_node* find = slt_find(plist, 1);
	slt_insert(&plist, find, 33);
	slt_print(plist);

	slt_insert_after(find, 55);
	slt_print(plist);

	find = slt_find(plist, 5);
	slt_insert_after(find, 6);
	slt_print(plist);
}

void slt_test05()
{
	slt_node* plist = NULL;
	slt_push_back(&plist, 1);
	slt_push_back(&plist, 2);
	slt_push_back(&plist, 3);
	slt_push_back(&plist, 4);
	slt_push_back(&plist, 5);
	slt_print(plist);
	slt_node* find = slt_find(plist, 3);
	slt_erase(&plist, find);
	slt_print(plist);

	find = slt_find(plist, 1);
	slt_erase(&plist, find);
	slt_print(plist);
}

void slt_test06()
{
	slt_node* plist = NULL;
	slt_push_back(&plist, 1);
	slt_push_back(&plist, 2);
	slt_push_back(&plist, 3);
	slt_push_back(&plist, 4);
	slt_push_back(&plist, 5);
	slt_print(plist);
	slt_node* find = slt_find(plist, 3);
	slt_erase_after(find);
	slt_print(plist);

}

void slt_test07()
{
	slt_node* plist = NULL;
	slt_push_back(&plist, 1);
	slt_push_back(&plist, 2);
	slt_push_back(&plist, 3);
	slt_push_back(&plist, 4);
	slt_push_back(&plist, 5);
	slt_print(plist);
 	slt_destroy(&plist);
}
int main()
{
	//creat_single_list();
	//slt_test01();
	//slt_test02();
	//slt_test03();
	//slt_test04();
	//slt_test05();
	//slt_test06();
	slt_test07();
	return 0;
}