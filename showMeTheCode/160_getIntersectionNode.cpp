#include <iostream>
#include <hash_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode temp = headA;
        Set<ListNode> visited = new HashSet<ListNode>();
        while(temp != NULL)
        {
            visited.add(temp);
            temp = temp.next;
        }
        temp = headB;
        while(temp != NULL)
        {
            if(visited.contains(temp))
                return temp;
            temp = temp.next;
        }
        return nullptr;
    }
};

//时间复杂度 o(m + n)
//空间负责度 o(m) 使用了hash_set

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;

        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        while(p != q)
        {
            p = (p == nullptr ? headB : p->next);
            q = (q == nullptr ? headA : q->next);
        }
        return p;
    }
};

//时间复杂度 o(m + n)
//空间负责度 o(1) 