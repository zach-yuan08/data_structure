#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

list_node* buy_node(data_type x)
{
	list_node* new_node = (list_node*)malloc(sizeof(list_node));
	if (new_node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	new_node->data = x;
	new_node->next = new_node->prve = new_node;
	return new_node;
}

void list_init(list_node** pphead)
{
	*pphead = buy_node(-1);
}

void list_print(list_node* phead)
{
	list_node* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

void list_push_back(list_node* phead, data_type x)
{
	assert(phead);
	list_node* new_node = buy_node(x);
	new_node->next = phead;
	new_node->prve = phead->prve;
	phead->prve->next = new_node;
	phead->prve = new_node;
}

void list_push_front(list_node* phead, data_type x)
{
	assert(phead);
	list_node* new_node = buy_node(x);
	new_node->next = phead->next;
	new_node->prve = phead;
	phead->next->prve = new_node;
	phead->next = new_node;
}

bool list_empty(list_node* phead)
{
	assert(phead);
	return phead->next == phead;
}

void list_pop_back(list_node* phead)
{
	list_empty(phead);
	assert(phead);
	list_node* del = phead->prve;
	phead->prve->prve->next = phead;
	phead->prve = phead->prve->prve;
	free(del);
	del = NULL;
}

void list_pop_front(list_node* phead)
{
	list_empty(phead);
	assert(phead);
	list_node* del = phead->next;
	phead->next->next->prve = phead;
	phead->next = phead->next->next;
	free(del);
	del = NULL;
}

list_node* list_find(list_node* phead, data_type x)
{
	list_node* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

void list_insert(list_node* pos, data_type x)
{
	assert(pos);
	list_node* new_node = buy_node(x);
	new_node->next = pos;
	new_node->prve = pos->prve;
	pos->prve->next= new_node;
	pos->prve = new_node;
}

void list_erase(list_node* pos)
{
	assert(pos);
	pos->prve->next = pos->next;
	pos->next->prve = pos->prve;
	free(pos);
	pos = NULL;
}

void list_destroy(list_node** pphead)
{
	assert(pphead && *pphead);
	list_node* pcur = (*pphead)->next;
	while (pcur != *pphead)
	{
		list_node* del = pcur;
		pcur = pcur->next;
		free(del);
		del = NULL;
	}
	free(*pphead);
	*pphead = NULL;
	pcur = NULL;
}

