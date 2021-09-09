#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;

        //新建一个节点，在head之前插入的时候用
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        //设立一个排序后最大值的标识位,初始化先放到head上
        ListNode* lastSorted = head;
        //设立一个排序的当前位置
        ListNode* curr = head->next;

        while(curr != nullptr)
        {
            if(lastSorted->val <= curr->val)
            {
                lastSorted = lastSorted->next; //如果比当前的小，则改变标识位为curr
            }
            else{
                ListNode* prev = dummyHead; //开始从头遍历，curr可以的插入位置
                while(prev->next->val <= curr->val)
                {
                    prev = prev->next; //如果prev指向的节点没有比curr大，则不是合适位置，继续往后
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};