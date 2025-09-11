#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int data_type;
typedef struct list_node
{
	data_type data;
	struct list_node* next;
	struct list_node* prve;
}list_node;

list_node* buy_node(data_type x);

void list_init(list_node** pphead);

void list_print(list_node* phead);

void list_push_back(list_node* phead, data_type x);

void list_push_front(list_node* phead, data_type x);

bool list_empty(list_node* phead);

void list_pop_back(list_node* phead);

void list_pop_front(list_node* phead);

list_node* list_find(list_node* phead, data_type x);

// 在指定位置之前插入
void list_insert(list_node* pos, data_type x);

void list_erase(list_node* pos);

void list_destroy(list_node** pphead);