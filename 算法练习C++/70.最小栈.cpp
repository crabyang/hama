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
        //实例化
        min_stack.push(INT_MAX);  //因为要维护最小栈，所以说基地入栈一个最大值
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
        //注意这是有返回值的,这是正常取栈顶
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