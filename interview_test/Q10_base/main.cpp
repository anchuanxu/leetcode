#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//创建链表函数
ListNode* createLinkedList(int arr[], int n){
   if(n == 0)
       return NULL;

   //创建头节点
   ListNode* head = new ListNode(arr[0]);

   ListNode* curNode = head;
   for(int i = 1; i < n; i++){
       curNode->next = new ListNode(arr[i]);
       curNode = curNode->next;
   }
    return head;
}

//打印链表函数
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while (curNode != NULL){
        cout<< curNode->val<<" -> ";
        curNode = curNode->next;
    }

    cout<<"NULL"<<endl;
    return;
}

//内存释放函数
void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete(delNode);
    }
    return;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode *next = cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;

    }
};

/*
ListNode* CreatList(){
    ListNode* pNode = new ListNode(0);
    pNode->next = NULL;
    ListNode* pHead = pNode;

    for (int i = 1; i < 5; i++) {
        ListNode* pTemp = new ListNode(i);
        pNode->next = pTemp;
        pNode = pTemp;
    }
    return pHead;
}


void printList(ListNode* pHead){
    ListNode* pTraverse = pHead;
    if (!pTraverse) {
        return;
    }
    while (pTraverse) {
        cout<< pTraverse->val << " ";
        pTraverse = pTraverse->next;
    }
    cout<< endl;
}
 */


int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/ sizeof(int);

    ListNode* head = createLinkedList(arr ,n);
    printLinkedList(head);

    ListNode* head2 = Solution().reverseList(head);
    printLinkedList(head2);

    deleteLinkedList(head2);
    return 0;
}