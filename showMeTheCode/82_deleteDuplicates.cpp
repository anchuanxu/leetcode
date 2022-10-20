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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while(cur->next && cur->next->next)
        {
            if(cur->next->val == cur->next->next->val)
            {
                int value = cur->next->val;
                while(cur->next && cur->next->val == value)
                {
                    cur->next = cur->next->next;
                }
            } else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

class Solution2 {
public:
    string simplifyPath(string path) {
        deque<string> ds;

        int n = path.size();
        int i = 0;
        while (i < n)
        {
            if(i < n && path[i] == '/')
            {
                i++;
            } else{
                string part;
                while(i < n && path[i] != '/')
                {
                    part += path[i++];
                }
                if(part == ".." && !ds.empty()) ds.pop_back();
                else if(part != ".." && part != ".") ds.push_back(part);
            }
        }
        string res = "/";
        while (!ds.empty())
        {
            res += ds.front() + "/";
            ds.pop_front();
        }
        if(res.size() > 1)
        {
            res.pop_back();
        }

        return res;

    }
};

int main() {
    Solution solution;
    return 0;
}
