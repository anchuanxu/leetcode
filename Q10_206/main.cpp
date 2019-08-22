#include <iostream>
using namespace std;

 //Definition for singly-linked list.
struct ListNode {
   int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main() {
    ListNode* p = CreatList();
    ListNode* res;
    res = Solution().reverseList(p);
    printList(res);
    return 0;
}