#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        p.push(x);
    }

    //获得队首元素的时候,必须先将栈反转,把先进入的元素放在栈顶,这样就符合了队列的先进先出
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (q.empty()) {
            while (!p.empty()) {
                q.push(p.top());
                p.pop();
            }
        }
        int x= q.top();
        q.pop();
        return x;

    }

    /** Get the front element. */
    int peek() {
        if (q.empty()) {
            while (!p.empty()) {
                q.push(p.top());
                p.pop();
            }
        }
        return q.top();

    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return p.empty()&&q.empty();
    }


private:
    stack<int>p,q;
};

int main() {

    return 0;
}