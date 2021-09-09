#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        if(head == nullptr) return nullptr;

        while (cur->next != nullptr)
        {
            if(cur->val == cur->next->val)
            {
                ListNode* p = nullptr;
                p = cur->next;
                cur->next = cur->next->next;
                delete p;   
            }
            else{
                cur = cur->next;
            }
        }

        return head;  
    }
};