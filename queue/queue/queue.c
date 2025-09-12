
#include"queue.h"

void queue_init(queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// 队列的结构是由对头指向队尾,这太不符合常规的逻辑
// 因为我想的是队列应该像排队那样，第一个面朝前的人是对头
// 所以对头的前面也就是next是没有人的也就是null
// 但是队列的结构不是这样，理解队列结构
void queue_push(queue* pq, queue_data_type x)
{
	assert(pq);
	queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));
	if (new_node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}

	new_node->data = x;
	new_node->next = NULL;
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = new_node;
	}
	else
	{
		pq->ptail->next = new_node;
		pq->ptail = new_node;
	}
	pq->size++;
}

bool queue_empty(queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}
void queue_pop(queue* pq)
{
	assert(pq);
	assert(!queue_empty(pq));
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		queue_node* del = pq->phead;
		pq->phead = pq->phead->next;
		free(del);
		del = NULL;
	}
	pq->size--;
}

queue_data_type queue_front(queue* pq)
{
	assert(pq);
	assert(!queue_empty(pq));
	return pq->phead->data;
}

queue_data_type queue_back(queue* pq)
{
	assert(pq);
	assert(!queue_empty(pq));
	return pq->ptail->data;
}

int queue_size(queue* pq)
{
	return pq->size;
}

void queue_destroy(queue* pq)
{
	assert(pq);
	while (pq->size)
	{
		queue_node* del = pq->phead;
		pq->phead = pq->phead->next;
		free(del);
		del = NULL;
		pq->size--;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}