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
        if (!head || !head->next){
            return head;
        }
        ListNode *slow = head,*fast = head,*pre = head;
        //下面使用了快慢指针
        while (fast && fast->next){
            pre = slow ;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head),sortList(slow));
    }
    ListNode *merge(ListNode *l1,ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;//dummy是头结点,cur是移动结点
        while (l1 && l2){
            if (l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1){
            cur->next = l1;
        }
        if (l2){
            cur->next = l2;
        }
        return dummy->next;
    }
    ListNode *CreateList(ListNode *l1){
        l1 = new ListNode(-1);
        ListNode *head = l1;
        int x= 0;
        cout<<"请输入节点: ";
        for (int i = 0; i < 5; ++i) {
            ListNode *p = new ListNode(-1);
            cin>>x;
            p->val = x;
            l1->next = p;
            l1 = p;
        }
        return head;
    }
};
int main() {
    ListNode * p = new ListNode(-1);
    ListNode *head;
    Solution *s = new Solution;
    p=s->CreateList(p);
    head = s->sortList(p)->next;
    while (head){
        cout<<head->val<<"\t";

        head = head->next;
    }
    return 0;
}