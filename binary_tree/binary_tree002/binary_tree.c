#define _CRT_SECURE_NO_WARNINGS 1
#include"binary_tree.h"
#include"queue.h"

btnode* buy_node(binary_tree_data_type x)
{
	btnode* new_node = (btnode*)malloc(sizeof(btnode));
	if (new_node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	new_node->data = x;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void preorder_traversal(btnode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void inorder_traversal(btnode* root)
{
	if (root == NULL)
		return;
	inorder_traversal(root->left);
	printf("%d ", root->data);
	inorder_traversal(root->right);
}

void subsequent_traversal(btnode* root)
{
	if (root == NULL)
		return;
	subsequent_traversal(root->left);
	subsequent_traversal(root->right);
	printf("%d ", root->data);
}

int binary_tree_size(btnode* root)
{
	if (root == 0)
		return 0;
	return 1 + binary_tree_size(root->left) + binary_tree_size(root->right);
}

int binary_tree_leaf_size(btnode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return binary_tree_leaf_size(root->left) + binary_tree_leaf_size(root->right);
}

int binary_tree_levelK_size(btnode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return binary_tree_levelK_size(root->left, k - 1) + binary_tree_levelK_size(root->right, k - 1);
}

int binary_tree_depth(btnode* root)
{
	if (root == 0)
		return 0;
	int left_depth = binary_tree_depth(root->left);
	int right_depth = binary_tree_depth(root->right);
	return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

btnode* binary_tree_find(btnode* root, binary_tree_data_type x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	btnode* left_find = binary_tree_find(root->left, x);
	if (left_find->data)
		return left_find;
	btnode* right_find = binary_tree_find(root->right, x);
	if (right_find->data)
		return right_find;
	return NULL;
}

void binary_tree_destroy(btnode** proot)
{
	if (*proot == NULL)
		return;
	binary_tree_destroy(&((*proot)->left));
	binary_tree_destroy(&((*proot)->right));
	free(*proot);
	*proot = NULL;
}

void level_traversal(btnode* root)
{
	queue q;
	queue_init(&q);
	queue_push(&q, root);
	while (!queue_empty(&q))
	{
		btnode* front = queue_front(&q);
		printf("%d ", front->data);
		queue_pop(&q);
		if (front->left)
			queue_push(&q, front->left);
		if (front->right)
			queue_push(&q, front->right);
	}
	queue_destroy(&q);
}

bool binary_tree_complete(btnode* root)
{
	queue q;
	queue_init(&q);
	queue_push(&q, root);
	while (!queue_empty(&q))
	{
		btnode* front = queue_front(&q);
		queue_pop(&q);
		if (front == NULL)
			break;
		queue_push(&q, front->left);
		queue_push(&q, front->right);
	}
	while (!queue_empty(&q))
	{
		btnode* front = queue_front(&q);
		queue_pop(&q);
		if (front != NULL)
		{
			queue_destroy(&q);
			return false;
		}
	}
	queue_destroy(&q);
	return true;
}