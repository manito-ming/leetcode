#include <iostream>
#include <queue>
using namespace std;
//解法一
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        //直接将最后一个元素插入到队首
        for (int i = 0; i < q.size()-1; ++i) {
            //将前面的元素取出放在最后
            q.push(q.front());
            q.pop();

        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int i = q.front();
         q.pop();
        return i;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    queue<int>q;
};
//解法二
class MyStack1 {
public:
    /** Initialize your data structure here. */
    MyStack1() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int size =q.size();
        //将q队列里面只保留一个最后进来的,其他的保存在p中
        for (int i = 0; i < size -1; ++i) {
            p.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int i = top();
        q.pop();
        return i;
    }

    /** Get the top element. */
    int top() {
        if (q.empty()){
            //将队列倒
            int size = p.size();
            if (size == 0){
                return 0;
            }
            //将先后顺序调换一下
            for (int i = 0; i < size-1; ++i) {
                p.push(p.front());
                p.pop();
            }
            q.push(p.front());
            p.pop();
        }
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return p.empty()&&q.empty();
    }

private:
    queue<int>q,p;
};
int main() {
     MyStack *obj = new MyStack;
     int x = 2;
     obj->push(x);
     int param_2 = obj->pop();
     int param_3 = obj->top();
     bool param_4 = obj->empty();
     cout<<"param_2: "<<param_2<<" param_3: "<<param_3<<" param_4: "<<param_4<<endl;

    MyStack1 *obj1 = new MyStack1;
    obj1->push(x);
    int param1_2 = obj1->pop();
    int param1_3 = obj1->top();
    bool param1_4 = obj1->empty();
    cout<<"param1_2: "<<param1_2<<" param1_3: "<<param1_3<<" param1_4: "<<param1_4<<endl;
    return 0;

}