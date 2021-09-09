//评测题目: 无
/**
1.	题目描述：   将输入的一个单向链表，逆序后输出链表中的值。
要求实现函数
【输入】head：    链表头节点，空间已经开辟好 
【输出】head：    逆序后的链表头节点
**/

class Solution{
  public:
  void reverse(ListNode* head)
  {
  	ListNode* cur = head;
    ListNode* pre = NULL;
    
    while(cur != NULL)
    {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  }
  
  void print(ListNode* head)
  {
    ListNode* p = head;
  	while(p != NULL)
    {
    	std::cout << p->val << std::endl;
    }
  } 
};





/**
2.网球中心共有100个网球场，每个单位可以来申请1到100的场地，申请的场地编号必须是连续的，
如果场地已经被其他单位占用，就不能再次使用，而且单位在使用完场地后必须归还，请设计一个完整的系统。
**/
class Solution{
  public:
  
  vector<bool> mat(false, 100);
  
  bool func(int start, int end)
  {
    
    for(int i = start; i <= end; i++)
    {
    	if(mat[i]) return false;
  		else mat[i] = true;
    }
    return true;
  }
  
  void del(int start, int end)
  {
  	for(int i = start; i <= end; i++)
    {
    	mat[i] = false;
    }
	return;
  }
  }
};










