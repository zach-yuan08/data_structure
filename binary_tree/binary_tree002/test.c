#define _CRT_SECURE_NO_WARNINGS 1
#include"binary_tree.h"

void binary_tree_test01()
{
	btnode* node1 = buy_node(1);
	btnode* node2 = buy_node(2);
	btnode* node3 = buy_node(3);
	btnode* node4 = buy_node(4);

	node1->left = node2;
	node1->right = node3;
	node2->right = node4;
	preorder_traversal(node1);
	printf("\n");
	inorder_traversal(node1);
	printf("\n");
	subsequent_traversal(node1);
	printf("\n");
}

void binary_tree_test02()
{
	btnode* node1 = buy_node(1);
	btnode* node2 = buy_node(2);
	btnode* node3 = buy_node(3);
	btnode* node4 = buy_node(4);

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	printf("size = %d", binary_tree_size(node1));
	printf("\n");
	printf("leaf size = %d", binary_tree_leaf_size(node1));
	printf("\n");
	printf("第3层结点个数 = %d", binary_tree_levelK_size(node1, 3));
	printf("\n");
	printf("depth = %d", binary_tree_depth(node1));
	printf("\n");

	btnode* find = binary_tree_find(node1, 4);
	printf("%s\n", find == NULL ? "未找到" : "找到了");
	printf("\n");

	level_traversal(node1);
	printf("\n");

	printf("%s", binary_tree_complete(node1) == true ? "是完全二叉树" : "不是完全二叉树");
	binary_tree_destroy(&node1);
}

int main()
{
	//binary_tree_test01();
	binary_tree_test02();
	return 0;
}