#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if(minStk.empty())
            minStk.push(val);
        else{
            if(minStk.top() >= val){
                minStk.push(val);
            }
        }
    }
    
    void pop() {
        if(stk.top() == minStk.top()){
            minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << " ";
    obj->pop();
    cout << obj->top() << " ";
    cout << obj->getMin() << " ";
    return 0;
}