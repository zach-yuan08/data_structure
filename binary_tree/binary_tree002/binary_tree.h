#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int binary_tree_data_type;
typedef struct binary_tree_node
{
	struct binary_tree_node* left;
	struct binary_tree_node* right;
	binary_tree_data_type data;
}btnode;

btnode* buy_node(binary_tree_data_type x);

void preorder_traversal(btnode* root);

void inorder_traversal(btnode* root);

void subsequent_traversal(btnode* root);

int binary_tree_size(btnode* root);

int binary_tree_leaf_size(btnode* root);

int binary_tree_levelK_size(btnode* root, int k);

int binary_tree_depth(btnode* root);

btnode* binary_tree_find(btnode* root, binary_tree_data_type x);

void binary_tree_destroy(btnode** proot);

void level_traversal(btnode* root);

bool binary_tree_complete(btnode* root);