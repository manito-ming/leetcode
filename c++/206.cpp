#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if(!head){
            return head;
        }
        ListNode *headnode=new ListNode(-1);
        headnode->next=head;
        ListNode* n = head;
        while (n->next){
            ListNode * temp = n->next;
            n->next = temp->next;
            //下面使用了头插法
            temp->next=headnode->next;
            headnode->next=temp;

        }
        return headnode->next;
    }
};
int main() {

    return 0;
}