#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct slt_node
{
	struct slt_node* next;
	int data;
}node;

node* buy_node(int x)
{
	node* new_node = (node*)malloc(sizeof(node));
	if (new_node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	new_node->next = NULL;
	new_node->data = x;
	return new_node;
}
//void push_back(node** pphead, int x)
//{
//	node* new_node = buy_node(x);
//	if (*pphead == NULL)
//	{
//		*pphead = new_node;
//	}
//	else
//	{
//		node* pcur = *pphead;
//		while (pcur->next)
//		{
//			pcur = pcur->next;
//		}
//		pcur->next = new_node;
//	}
//}

// 这里传参 phead是plist的临时拷贝没有错，拷贝的是plist中的数据
// phead也指向null，而phead和plist的地址不一样，所以改变phead和plist没有关系
void push_back(node* phead, int x)
{
	node* new_node = buy_node(x);
	if (phead == NULL)
	{
		phead = new_node;
	}
	else
	{
		node* pcur = phead;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = new_node;
	}
}

int main()
{
	node* plist = NULL;
	/*push_back(&plist, 1);
	push_back(&plist, 2);
	push_back(&plist, 3);
	push_back(&plist, 4);*/
	push_back(plist, 1); 
	push_back(plist, 2);
	push_back(plist, 3);
	push_back(plist, 4);
	return 0;
}