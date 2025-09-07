#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int sl_data_type;
typedef struct sequence_list
{
	sl_data_type* arr;
	int capacity;
	int size;
}sl;

void sl_init(sl* ps);

void sl_destroy(sl* ps);

void sl_check_capacity(sl* ps);

void sl_push_back(sl* ps, sl_data_type x);

void sl_print(sl* ps);

void sl_push_front(sl* ps, sl_data_type x);

void sl_pop_back(sl* ps);

void sl_pop_front(sl* ps);

void sl_insert(sl* ps, sl_data_type x, size_t pos);

void sl_erase(sl* ps, size_t pos);

int sl_find(sl* ps, sl_data_type x);