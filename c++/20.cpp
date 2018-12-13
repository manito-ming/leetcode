#include <iostream>
using namespace std;

typedef int Status;
typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkStackPtr;                        //链栈的一个结点定义

typedef struct{
    LinkStackPtr top;
}LinkStack;
class Solution {
public:
    bool isValid(string s) {

        LinkStack s1;
        char ch='\0';
        InitStack(&s1);
        const char *p = s.c_str();
        for(int i=0;i<s.size();i++) {
            char c = p[i];
            switch (p[i]) {
                case '(':
                case '[':
                case '{':
                    Push(&s1, p[i]);
                    break;
                case ')':
                case ']':
                case '}':
                    if (s1.top == NULL) {
                        cout << "右括号多余"<<"2"<<endl;
                        return false;
                    }
                    else{
                        GetTop(&s1,&ch);///ch是出栈的那个元素
                        if(Match(ch,p[i]))///查看是否符合
                            Pop(&s1,&ch);///如果符合就出栈
                        else{
                            cout<<"括号不匹配"<<"1"<<endl;
                            return false;
                        }
                    }
                    break;
            }
        }
        if(s1.top == NULL){
            cout << "括号匹配";
            return true;
        }else{
            cout<<"左括号多余";
            return false;

        }
    }
    Status InitStack(LinkStack *s)
    {
        s->top=new Node;
        if(s->top==NULL) {
            cout<<"分配空间失败!"<<endl;
            return false;
        }
        s->top=NULL;
    }
///入栈
    Status Push(LinkStack *s,ElemType e)
    {
        //相当于头插法,首先创建一个新节点赋值,然后将新节点的下一个指向原先的栈顶元素,最后将栈顶元素指向新节点

        LinkStackPtr ptr=new Node;        //创建一个结点
        ptr->data=e;                                //将元素c压入栈顶
        ptr->next=s->top;                        //把当前栈顶元素赋值给新结点的直接后继
        s->top=ptr;                                //改变栈顶指针，top指向新结点p
        return true;
    }
    Status Pop(LinkStack *s,ElemType *e)        //出栈时需判断是否栈空
    {
        LinkStackPtr p;
        if(s->top==NULL)
        {
            cout<<"栈空!";
            return false;
        }
        else
        {
            *e=s->top->data;
            p=s->top;
            s->top=s->top->next;//然后栈顶的指针指向下一个节点,也就是说执行完这句话,栈顶的指针指向了原先栈顶指针的下一个,下一句就可以删除原来的栈顶的节点了
            free(p);
            return true;
        }
    }
    Status GetTop(LinkStack *s,ElemType *e)                //要定义指针类型来进行接收数据
    {
        if(s->top!=NULL)
        {
            *e=s->top->data;
            cout<<*e<<"      gettop"<<endl;
        }
        else{
            cout<<"栈空!";
            return false;
        }
        return true;
    }
    Status Match(char ch1,char ch2)
    {
        if(ch1=='(' && ch2==')')
            return true;
        if(ch1=='[' && ch2==']')
            return true;
        if(ch1=='{' && ch2=='}')
            return true;
        else
            return false;
    }
};
int main() {
    string s="()";
    Solution *s1 = new Solution;
    cout<<s1->isValid(s);

    return 0;
}