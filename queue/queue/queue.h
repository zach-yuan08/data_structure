#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct binary_tree_node* queue_data_type;
typedef struct queue_node
{
	queue_data_type data;
	struct queue_node* next;
}queue_node;

typedef struct queue
{
	queue_node* phead;
	queue_node* ptail;
	int size;
}queue;

void queue_init(queue* pq);

void queue_push(queue* pq, queue_data_type x);

bool queue_empty(queue* pq);

void queue_pop(queue* pq);

queue_data_type queue_front(queue* pq); // 取对头元素

queue_data_type queue_back(queue* pq);

int queue_size(queue* pq);

void queue_destroy(queue* pq);