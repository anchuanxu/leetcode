#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//使用无序表法，时间复杂度o(N) 空间复杂度o(N)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while(head != nullptr)
        {
            if(visited.count(head))
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};

//使用快慢指针法，时间复杂度o(N),空间复杂度o(1)
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};