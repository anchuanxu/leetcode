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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr)
        {
            return head;
        }

        int n = 1;
        ListNode* iter = head;
        while(iter->next != nullptr)
        {
            n++;
            iter = iter->next;
        }

        if(k % n == 0)
        {
            return head;
        }

        iter->next = head;
        iter = iter->next;
        int count = 0;
        while(count != n - 1 - k % n) //iter 移动到新的尾巴节点处，从0开始计数，就是第n - 1 - k % n个节点
        {
            count++;
            iter = iter->next;
        }
        head = iter->next;
        iter->next = nullptr;
        return head;
    }
};


int main()
{
    return 0;
}