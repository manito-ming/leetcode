#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);//head指针是每次后移的
        ListNode* firstNode = head;
        l1 = l1->next;
        l2 = l2->next;
        while (l1!=NULL && l2!=NULL)
        {
            if (l1->val > l2->val)
            {
                firstNode->next = l2;
                l2 = l2->next;
            } else{
                firstNode->next = l1;
                l1 = l1->next;
            }
            firstNode =firstNode->next ;
        }
        firstNode->next = l1?l1:l2;
        return head;
    }

    //创建一个单链表
    ListNode* CreateTwoList(ListNode *l1) {
        l1=new ListNode(-1);
        ListNode *n=l1;
        int x=0;
        for (int i = 0; i <3; ++i) {
            ListNode *p=new ListNode(-1);
            cin >> x;

            p->val=x;
            l1->next = p;
            l1 = p;

        }


        return n;
    }
    ListNode* CreateOneList(ListNode *l2){
        l2=new ListNode(-1);
        ListNode *n=l2;
        int x=0;
        for (int i = 0; i <3; ++i) {
            ListNode *q=new ListNode(-1);
            cin >> x;
            q->val=x;
            l2->next = q;
            l2 = q;

        }
        return n;
    }
};
int main() {
    Solution *s = new Solution();
    ListNode *l1,  *l2;
    ListNode *ll1,  *ll2;
    ll1 = (*s).CreateTwoList(l1);
    ll2 = (*s).CreateOneList(l2);
    ListNode *suml = (*s).mergeTwoLists(ll1,ll2);
    while(suml != NULL)
    {
        if (suml->next  != NULL )
        {
            suml = suml->next;
            cout<<suml->val<<"\t";
        } else{
            suml = suml->next;
        }
    }
    return 0;
}