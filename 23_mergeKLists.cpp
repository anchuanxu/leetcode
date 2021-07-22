//
// Created by 传旭 on 2021/7/20.
//
#include <iostream>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (a == nullptr && b == nullptr) return nullptr;
        if (a == nullptr && b != nullptr) return b;
        if (a != nullptr && b == nullptr) return a;

//        if (!a || !b) return a ? a : b;
//        else return nullptr;

        ListNode head;
        ListNode *res;
        ListNode *p = a, *q = b;
        res = &head;

        while (p && q)
        {
            if (p->val < q->val)
            {
                res->next = p;
                p = p->next;
            }
            else{
                res->next = q;
                q = q->next;
            }
            res = res->next;
        }
        res->next = p ? p : q; //p不空，将p传入，p空将q传入

        return head.next;
    }

    ListNode* merge(vector<ListNode*> &lists, int l, int r)
    {
        if (l == r) return lists[l];
        if (l > r)  return nullptr;

        int mid = (l + r) >> 1; //移位运算符 移动一位 等于除以2的1次方
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
};

int main()
{
//    Solution solution;
//    vector<ListNode*>& lists = {};
//    ListNode* result;
//
//    result = solution.mergeKLists(lists);
//
//    while (result != nullptr)
//    {
//        cout << result->val;
//        result->next = result;
//    }
    return 0;
}