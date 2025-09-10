#define _CRT_SECURE_NO_WARNINGS 1
#include"single_list.h"

void slt_print(slt_node* phead)
{
	slt_node* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

slt_node* slt_buy_node(slt_data_type x)
{
	slt_node* node = (slt_node*)malloc(sizeof(slt_node));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	node->next = NULL;
	node->data = x;
	return node;
}

// 想起来我第一次学这里的时候无论咋样都弄不明白这里为什么用二级指针，当时真的快哭了
// 哈哈哈 现在还是废了一些力气，总算是拿下了
// 忽然有个了个很直白的解释，因为要更改node1，所以肯定要传地址
// 自然也就用二级指针接收了 
void slt_push_back(slt_node** pphead, slt_data_type x)
{
	assert(pphead);
	slt_node* new_node = slt_buy_node(x);
	if (*pphead == NULL)
	{
		*pphead = new_node; // *pphead = node1
	}
	else
	{
		slt_node* pcur = *pphead;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = new_node;
	}
}

// wow 我自己写出来了一个方法
// 这里用返回值就可以避免二级指针
//slt_node* slt_push_front(slt_node* phead, slt_data_type x)
//{
//	slt_node* new_noed = slt_buy_node(x);
//	new_noed->next = phead;
//	return new_noed;
//}

void slt_push_front(slt_node** pphead, slt_data_type x)
{
	assert(pphead);
	slt_node* new_node = slt_buy_node(x);
	new_node->next = *pphead;
	*pphead = new_node;
}

void slt_pop_back(slt_node** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		slt_node* ptail = *pphead;
		slt_node* prev = NULL;

		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

void slt_pop_front(slt_node** pphead)
{
	assert(*pphead && pphead);
	slt_node* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;
}

slt_node* slt_find(slt_node* phead, slt_data_type x)
{
	assert(phead);
	slt_node* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

void slt_insert(slt_node** pphead, slt_node* pos, slt_data_type x)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)
	{
		slt_push_front(pphead, x);
	}
	else
	{
		slt_node* new_node = slt_buy_node(x);
		slt_node* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		new_node->next = pos;
		prev->next = new_node;
	}
}

void slt_insert_after(slt_node* pos, slt_data_type x)
{
	assert(pos);
	slt_node* new_node = slt_buy_node(x);
	new_node->next = pos->next;
	pos->next = new_node;
}

void slt_erase(slt_node** pphead, slt_node* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	slt_node* prev = *pphead;
	if (pos == *pphead)
	{
		slt_pop_front(pphead);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void slt_erase_after(slt_node* pos)
{
	assert(pos && pos->next);
	slt_node* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

void slt_destroy(slt_node** pphead)
{
	assert(pphead && *pphead);
	slt_node* pcur = *pphead;
	while (pcur)
	{
		slt_node* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}