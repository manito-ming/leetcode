#include <iostream>
#include <vector>

using namespace std;
 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            //使用了21题的函数,将链表分为两部分,将前半部分与后半部分相同位置的链表开始合并
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head->next;
    }
};
//这个解法稍稍有点缺陷,不知道该怎么去完善
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode * list=new ListNode(-1);
        if (lists.empty()){
            list = NULL;
            return list;
        }
        list= lists[0];
        ListNode *head;
        ListNode *node;
        ListNode *p;
        for (int i = 1; i < lists.size(); ++i) {
            if (list==NULL){
                list = lists[i];
            }
            head = list;
            node = lists[i];
            while (node!= NULL){
                p=node->next;
                if (head!=NULL && head->next!=NULL){
                    if (head->val<node->val && head->next->val<node->val){
                        head=head->next;

                    } else{
                        node->next = head->next;
                        head->next=node;
                        head=head->next;
                        node=p;
                    }
                } else{
                    if (head->val<node->val){
                        node->next = head->next;
                        head->next=node;
                        head=head->next;
                        node=p;
                    } else{
                        //这有错误
//                        head->next = node->next;
//                        node->next = head;
//                        list = node;
//                        node = node->next->next;
                    }
                }

            }

        }
        return list;
    }
    ListNode* CreateOneList(ListNode *l1) {
        l1=new ListNode(-1);
        ListNode *n=l1;
        int x=0;
        for (int i = 0; i <1; ++i) {
            ListNode *p=new ListNode(-1);
            cin >> x;

            p->val=x;
            p->next=l1->next;
            l1->next=p;
            l1=l1->next;
        }

        return n->next;
    }
};
int main() {
    Solution *s1= new Solution;
    Solution1 *s= new Solution1;
    ListNode *l1;
    ListNode *l2;
    ListNode *l3;
    ListNode *l4;

//    l1=s->CreateOneList(l1);
    l2=s->CreateOneList(l2);
//    l3=s->CreateOneList(l3);
    l4 = NULL;

    vector<ListNode *> lists={l4,l2};
    s1->mergeKLists(lists);
    return 0;
}