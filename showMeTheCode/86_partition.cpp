#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;

        while(head != nullptr)
        {
            if(head->val < x)
            {
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }

    ListNode* creatLinkedList(vector<int> arr)
    {
        if(arr.empty()) return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* curNode = head;
        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* node = new ListNode(arr[i]);
            curNode->next = node;
            curNode = node;
        }

        return head;
    }

    void printLinkedList(ListNode* head)
    {
        if(head == nullptr) return;

        ListNode* curNode = head;
        while(curNode != nullptr)
        {
            cout << curNode->val << " ";
            curNode = curNode->next;
        }
        cout << endl;
        return;
    }

    void deleteLinkedList(ListNode* head)
    {
        if(head == nullptr) return;

        ListNode* curNode = head;
        while (curNode != nullptr)
        {
            ListNode* delNode = curNode;
            curNode = curNode->next;
            delete(delNode);
        }

        return;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,4,3,2,5,2};
    ListNode* head;
    head = solution.creatLinkedList(nums);
    solution.printLinkedList(head);
    head = solution.partition(head,3);
    solution.printLinkedList(head);
    solution.deleteLinkedList(head);
    return 0;
}
