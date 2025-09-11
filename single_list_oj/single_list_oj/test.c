#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// https://leetcode.cn/problems/remove-linked-list-elements/

 // Definition for singly-linked list.
//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
// 
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* pcur = head;
//    struct ListNode* prev = pcur;
//    while (pcur) {
//        if (head->val == val) {
//            struct ListNode* del = pcur;
//            head = head->next;
//            pcur = head;
//            prev = head;
//            free(del);
//            del = NULL;
//        }
//        else {
//            if (pcur->val == val) {
//                prev->next = pcur->next;
//                struct ListNode* del = pcur;
//                pcur = pcur->next;
//                free(del);
//                del = NULL;
//            }
//            else {
//                prev = pcur;
//                pcur = pcur->next;
//            }
//        }
//    }
//    return head;
//}
// emmm 这个方法有点挫 我写的感觉很冗余 
// 方法二 空间换时间


// https://leetcode.cn/problems/reverse-linked-list/

 // Definition for singly-linked list.
//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//
//void push_front(ListNode** pphead, int x)
//{
//    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
//    new_node->next = *pphead;
//    new_node->val = x;
//    (*pphead) = new_node;
//}
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//    // 思路：搞一个新链表，进行头插
//    ListNode* new_head = NULL;
//    while (head)
//    {
//        push_front(&new_head, head->val);
//        head = head->next;
//    }
//    return new_head;
//}
//
// 第二种思路：三个指针实现原地反转
//
//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL) {
//        return head;
//    }
//    else {
//        ListNode* n1 = NULL;
//        ListNode* n2 = head;
//        ListNode* n3 = n2->next;
//        while (n2) {
//            n2->next = n1;
//            n1 = n2;
//            n2 = n3;
//            if (n3) {
//                n3 = n3->next;
//            }
//        }
//        return n1;
//    }
//}

// https://leetcode.cn/problems/middle-of-the-linked-list/
//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//
// 思路：快慢指针，快指针走两步，慢指针走一步
//struct ListNode* middleNode(struct ListNode* head)
//{
//    ListNode* fast, * slow;
//    slow = fast = head;
//    while (fast && fast->next) // 顺序有说法 不可以对空指解引用
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}

// https://leetcode.cn/problems/merge-two-sorted-lists/
//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//
// 思路：写一个尾插算法，遍历两个链表进行尾插
//void push_back(ListNode** pos, int x)
//{
//    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
//    new_node->next = NULL;
//    new_node->val = x;
//    if (*pos == NULL)
//    {
//        *pos = new_node;
//    }
//    else
//    {
//        ListNode* pcur = *pos;
//        while (pcur->next)
//        {
//            pcur = pcur->next;
//        }
//        pcur->next = new_node;
//    }
//}
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    ListNode* p1, * p2;
//    ListNode* new_list = NULL;
//    p1 = list1, p2 = list2;
//    while (p1 && p2);
//    {
//        if (p1->val <= p2->val)
//        {
//            push_back(&new_list, p1->val);
//            p1 = p1->next;
//        }
//        else
//        {
//            push_back(&new_list, p2->val);
//            p2 = p2->next;
//        }
//    }
//    while (p1)
//    {
//        push_back(&new_list, p1->val);
//        p1 = p1->next;
//    }
//    while (p2)
//    {
//        push_back(&new_list, p2->val);
//        p2 = p2->next;
//    }
//    return new_list;
//}
//
// 写的太挫了 时间复杂太高，超时了
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//
//    ListNode* p1, * p2;
//    p1 = list1, p2 = list2;
//    ListNode* phead, * ptail;
//    phead = ptail = NULL;
//    while (p1 && p2)
//    {
//        if (p1->val <= p2->val)
//        {
//            if (phead == NULL)
//            {
//                phead = ptail = p1;
//            }
//            else
//            {
//                ptail->next = p1;
//                ptail = ptail->next;
//            }
//            p1 = p1->next;
//        }
//        else
//        {
//            if (phead == NULL)
//            {
//                phead = ptail = p2;
//            }
//            else
//            {
//                ptail->next = p2;
//                ptail = ptail->next;
//            }
//            p2 = p2->next;
//        }
//    }
//    if (p1) // 这里写的漂亮，链表的优势，像小火车一样
//    {
//        ptail->next = p1;
//    }
//    if (p2)
//    {
//        ptail->next = p2;
//    }
//    return phead;
//}

// https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//typedef struct ListNode ListNode;
//
//// 思路：创建两个非空链表，一个放小于x的数据，另一个放大于x的数据
//ListNode* partition(ListNode* pHead, int x) 
//{
//    ListNode* less_head, * less_tail;
//    ListNode* greater_head, * greater_tail;
//    less_head = less_tail = (ListNode*)malloc(sizeof(ListNode));
//    greater_head = greater_head = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* pcur = pHead;
//    while (pcur)
//    {
//        if (pcur->val < x)
//        {
//            less_tail->next = pcur;
//            less_tail = less_tail->next;
//        }
//        else
//        {
//            greater_head->next = pcur;
//            greater_tail = greater_tail->next;
//        }
//        pcur = pcur->next;
//    }
//    greater_tail->next = NULL;
//    less_tail->next = greater_head->next;
//    ListNode* ret = less_head->next;
//    free(less_head);
//    less_head = NULL;
//    free(greater_head);
//    greater_head = NULL;
//
//    return ret;
//}

//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa

//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//typedef struct ListNode ListNode;
//bool chkPalindrome(ListNode* A) 
//{
//    ListNode* tmp = A;
//    int count = 0;
//    while (tmp)
//    {
//        tmp = tmp->next;
//        count++;
//    }
//    ListNode* fast, * slow;
//    fast = slow = A;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    if (count % 2 == 1)
//    {
//        slow = slow->next;
//    }
//    while (slow->next)
//    {
//        if (slow->val != A->val)
//            return false;
//        slow = slow->next;
//        A = A->next;
//    }
//    return true;
//}
// 癔症了，比较的逻辑有问题，需要反转前半段才能比较
// 思路：将链表内容放入数组中进行操作
//bool chkPalindrome(ListNode* A) {
//    int arr[900] = { 0 };
//    ListNode* pcur = A;
//    int i = 0;
//    while (pcur)
//    {
//        arr[i++] = pcur->val;
//        pcur = pcur->next;
//    }
//    int begin = 0;
//    int end = i - 1;
//    while (begin < end)
//    {
//        if (arr[begin++] != arr[end--])
//            return false;
//    }
//    return true;
//}
// 思路2：结合反转链表 妈呀 想想头都大了 要吐了 
//ListNode* find_mid_node(ListNode* head)
//{
//    ListNode* fast, * slow;
//    fast = slow = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//ListNode* reverse_node(ListNode* head)
//{
//    ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = (head)->next;
//    if (head == NULL)
//    {
//        return head;
//    }
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if(n3)
//            n3 = n3->next;
//    }
//    return n1;
//}
//
//bool chkPalindrome(ListNode* A) {
//    // 找中间结点
//    ListNode* mid_node = find_mid_node(A);
//    // 反转链表
//    ListNode* right = reverse_node(mid_node);
//    ListNode* left = A;
//    // 比较
//    while (right)
//    {
//        if (right->val != left->val)
//            return false;
//        right = right->next;
//        left = left->next;
//    }
//    return true;
//}
// 

// https://leetcode.cn/problems/intersection-of-two-linked-lists/
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) 
//{
//    // 找见差值
//    ListNode* l1 = headA;
//    ListNode* l2 = headB;
//    int size_a = 0;
//    int size_b = 0;
//    while (l1)
//    {
//        size_a++;
//        l1 = l1->next;
//    }
//    while (l2)
//    {
//        size_b++;
//        l2 = l2->next;
//    }
//    int gap = abs(size_a - size_b);
//
//    // 长的先走
//    ListNode* longlist = headA;
//    ListNode* shortlist = headB;
//    if (size_a < size_b)
//    {
//        longlist = headB;
//        shortlist = headA;
//    }
//    while (gap--)
//    {
//        longlist = longlist->next;
//    }
//    while (longlist && shortlist)
//    {
//        if (longlist == shortlist)
//            return longlist;
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//    return NULL;
//}

// https://leetcode.cn/problems/linked-list-cycle/
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//
//bool hasCycle(struct ListNode* head)
//{
//    ListNode* fast, * slow;
//    fast = slow = head;
//    while (fast && fast->next) {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//            return true;
//    }
//    return false;
//}

// https://leetcode.cn/problems/linked-list-cycle-ii/description/
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//// 思路：相遇点到入环结点的距离 == 头结点到入环结点的距离
//// 妙啊 具体为啥妙看课件上的图
//struct ListNode* detectCycle(struct ListNode* head) 
//{
//    ListNode* fast, * slow;
//    fast = slow = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == slow)
//        {
//            ListNode* meet = fast;
//            ListNode* pcur = head;
//            while (meet != pcur)
//            {
//                meet = meet->next;
//                pcur = pcur->next;
//            }
//            return meet;
//        }
//    }
//    return NULL;
//}

// https://leetcode.cn/problems/copy-list-with-random-pointer/description/

//struct Node {
//      int val;
//      struct Node *next;
//      struct Node *random;
//};
// 
//typedef struct Node Node;
//// 思路：在原链表的基础上复制链表
////       置random指针
////       断开链表
//
//Node* buy_node(int x)
//{
//    Node* new_node = (Node*)malloc(sizeof(Node));
//    new_node->next = NULL;
//    new_node->random = NULL;
//    new_node->val = x;
//    return new_node;
//}
//void add_node(Node* head)
//{
//    Node* pcur = head;
//    while (pcur)
//    {
//        Node* new_node = buy_node(pcur->val);
//        new_node->next = pcur->next;
//        pcur->next = new_node;
//        pcur = pcur->next->next;
//    }
//}
//struct Node* copyRandomList(struct Node* head) 
//{
//    if (head == NULL)
//    {
//        return NULL;  
//    }
//    add_node(head);
//    
//    Node* pcur = head;
//    while (pcur)
//    {
//        Node* copy = pcur->next;
//        if (pcur->random != NULL)
//        {
//            copy->random = pcur->random->next; // 妙啊 因为原链表已经和copy链表有了联系
//        }
//        pcur = copy->next;
//    }
//
//    pcur = head;
//    Node* new_head = head->next;
//    Node* new_tail = head->next;
//    while (pcur->next->next)
//    {   
//        pcur = pcur->next->next;
//        new_tail->next = pcur->next;
//        new_tail = new_tail->next;
//    } 
//
//    return new_head;
//}