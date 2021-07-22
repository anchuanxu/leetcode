#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//创建链表函数
ListNode* createLinkedList(int arr[], int n){
    if(n == 0)
        return NULL;

    //创建头节点
    ListNode* head = new ListNode(arr[0]);

    ListNode* curNode = head;
    for(int i = 1; i < n; i++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    return head;
}

//打印链表函数
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while (curNode != NULL){
        cout<< curNode->val<<" -> ";
        curNode = curNode->next;
    }

    cout<<"NULL"<<endl;
    return;
}

//内存释放函数
void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete(delNode);
    }
    return;
}
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        /*方法一
           //处理头结点
            while(head != NULL && head->val == val){
                ListNode* delNode = head;
                head = delNode->next;
                delete(delNode);
            }

            if(head == NULL)
                return NULL;

        */

        //方法二，建立虚拟头结点
        ListNode* dummyhead = new  ListNode(0);
        dummyhead->next = head;


        ListNode* cur = dummyhead;
        while(cur->next != NULL){
            if(cur->next->val ==  val){
                //删除cur->next;
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete(delNode);
            } else
                cur = cur->next;
        }

        ListNode* retNode = dummyhead->next;
        delete(dummyhead);
        return retNode;

    }
};



int main() {
    int arr[] = {1,2,3,4,4,5,4,8};
    ListNode* head;
    head = createLinkedList(arr,8);
    printLinkedList(head);

    Solution().removeElements(head,4);
    printLinkedList(head);

    deleteLinkedList(head);

    return 0;
}