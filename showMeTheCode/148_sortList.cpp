#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //使用快慢指针，找到链表的中点，然后分割成两个链表，对两个链表分别进行排序
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(head2));
    }
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(head1 == nullptr) return head2;
        else if(head2 == nullptr) return head1;
        else if(head1->val < head2->val)
        {
            head1->next = merge(head1->next, head2);
            return head1;
        }
        else{
            head2->next = merge(head1, head2->next);
            return head2;
        }
    }
};

//时间复杂度 o(nlogn)
//空间复杂度 o(1)