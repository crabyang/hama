#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
#include <stack>
using namespace std;


class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;

public:
    MinStack() {
        //ʵ����
        min_stack.push(INT_MAX);  //��ΪҪά����Сջ������˵������ջһ�����ֵ
    }

    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(val, min_stack.top()));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();

    }

    int top() {
        //ע�������з���ֵ��,��������ȡջ��
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */