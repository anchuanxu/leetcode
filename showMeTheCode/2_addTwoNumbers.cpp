//
// Created by 传旭 on 2021/7/22.
//
#include <iostream>
#include <vector>

using namespace std;

/*
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* h = head;
        int sum = 0;
        bool carry = false;

        while (l1 != NULL || l2 != NULL)
        {
            sum = 0;
            if (l1!= NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2!= NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
                sum++;
            h->next = new ListNode(sum % 10);
            h = h->next;
            carry = sum >= 10 ? true : false;
        }
        if(carry)
        {
            h->next = new ListNode(1);
            h = h->next;
        }
        return head->next;
    }
};

int main()
{
    return 0;
}
