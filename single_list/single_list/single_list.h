#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int slt_data_type;

typedef struct single_list_node
{
	slt_data_type data;
	struct single_list_node* next;
}slt_node;

void slt_print(slt_node* phead);

slt_node* slt_buy_node(slt_data_type x);

void slt_push_back(slt_node** pphead, slt_data_type x);

//slt_node* slt_push_front(slt_node* phead, slt_data_type x);
void slt_push_front(slt_node** pphead, slt_data_type x);

void slt_pop_back(slt_node** pphead);

void slt_pop_front(slt_node** pphead);

slt_node* slt_find(slt_node* phead, slt_data_type x);

void slt_insert(slt_node** pphead, slt_node* pos, slt_data_type x);

void slt_insert_after(slt_node* pos, slt_data_type x);

void slt_erase(slt_node** pphead, slt_node* pos);

void slt_erase_after(slt_node* pos);

void slt_destroy(slt_node** pphead);