#include <iostream>
using namespace std;
 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
//新建了一个链表作为排序链表来辅助存储已排好序的链表
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortlist = new ListNode(-1);
        ListNode* frist = sortlist;
        ListNode* n = head;
        while (n!=NULL){
            frist = sortlist;
            ListNode *p=n->next;
            //找到比val小的最大值,准备开始插入排序链表
            while (frist->next!=NULL&&frist->next->val<n->val){
                frist = frist->next;
            }
            n->next = frist->next;
            frist->next = n;
            n=p;//将这个节点插到排序链表之后,就需要继续开始遍历原来链表的下一个
        }

        return sortlist->next;
    }
    //创建一个单链表
    ListNode* CreateTwoList(ListNode *l1) {
        l1=new ListNode(-1);
        ListNode*node = l1;
        int x=0;
        for (int i = 0; i <4; ++i) {
            ListNode *p=new ListNode(-1);
            cin >> x;
//            if (x == 0)
//            {
//                break;
//            }
            p->val=x;
            node->next = p;
            node= node->next;

        }
//        cout<<"end l1"<<endl;

        return l1->next;
    }
};
int main() {
    Solution *s = new Solution;
    ListNode *l,*node;
    node = s->CreateTwoList(l);
    l = s->insertionSortList(node);
    return 0;
}