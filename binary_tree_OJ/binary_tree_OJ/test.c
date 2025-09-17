#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

// https://leetcode.cn/problems/univalued-binary-tree/

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
 
typedef struct TreeNode tree_node;
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//    int val = root->val; // 这里不对，每次进来value就被修改所以一定返回true
//    if (root->val != val)
//        return false;
//    isUnivalTree(root->left);
//    isUnivalTree(root->right);
//    return true;
//}

bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;
    if (root->left && root->left->val != root->val)
        return false;
    if (root->right && root->right->val != root->val)
        return  false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

// https://leetcode.cn/problems/same-tree/description/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// https://leetcode.cn/problems/symmetric-tree/description/
bool isSymmetric(struct TreeNode* root) {
    return isSameTree(root->left, root->right);
}

// https://leetcode.cn/problems/subtree-of-another-tree/description/
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (isSameTree(root, subRoot))
        return true;
    return  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// https://leetcode.cn/problems/binary-tree-preorder-traversal/
typedef struct TreeNode tree_node;

int tree_size(tree_node* root)
{
    if (root == NULL)
        return 0;
    return 1 + tree_size(root->left) + tree_size(root->right);
}
void _preorderTraversal(tree_node* root, int* arr, int* pi)
{
    if (root == NULL)
        return;
    arr[(*pi)++] = root->val;
    _preorderTraversal(root->left, arr, pi);
    _preorderTraversal(root->right, arr, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = tree_size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _preorderTraversal(root, arr, &i);
    return arr;
}

// https://leetcode.cn/problems/binary-tree-inorder-traversal/
typedef struct TreeNode tree_node;
int tree_size(tree_node* root) {
    if (root == NULL)
        return 0;
    return 1 + tree_size(root->left) + tree_size(root->right);
}

void _inorderTraversal(tree_node* root, int* arr, int* pi) {
    if (root == NULL)
        return;
    if (root->left != NULL) {
        _inorderTraversal(root->left, arr, pi);
    }
    arr[(*pi)++] = root->val;
    _inorderTraversal(root->right, arr, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = tree_size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _inorderTraversal(root, arr, &i);
    return arr;
}

// https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
typedef struct TreeNode tree_node;

int tree_size(tree_node* root) {
    if (root == NULL)
        return 0;
    return 1 + tree_size(root->left) + tree_size(root->right);
}
void _postorderTraversal(tree_node* root, int* arr, int* pi) {
    if (root == NULL)
        return;
    if (root->left != NULL)
        _postorderTraversal(root->left, arr, pi);
    _postorderTraversal(root->right, arr, pi);
    arr[(*pi)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = tree_size(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    _postorderTraversal(root, arr, &i);
    return arr;
}

// https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef
#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree_node {
    char data;
    struct binary_tree_node* left;
    struct binary_tree_node* right;
} btnode;

// 根据数组创建二叉树
btnode* buy_node(char x) {
    btnode* new_node = (btnode*)malloc(sizeof(btnode));
    new_node->data = x;
    new_node->left = new_node->right = NULL;
    return new_node;
}
btnode* creat_tree(char* arr, int* pi) {
    if (arr[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    btnode* root = buy_node(arr[(*pi)++]);
    root->left = creat_tree(arr, pi);
    root->right = creat_tree(arr, pi);
    return root;
}

void inorder(btnode* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

int main() {
    char arr[100];
    scanf("%s", arr);
    int i = 0;
    btnode* root = creat_tree(arr, &i);
    inorder(root);
    return 0;
}