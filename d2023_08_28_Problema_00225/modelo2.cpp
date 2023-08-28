class MyStack {
private:
    ListNode* minhaLista = nullptr;
public:
    MyStack() {
        // Nada a fazer
    }
    
    void push(int x) {
        minhaLista = new ListNode (x, minhaLista);
    }
    
    int pop() {
        int x = minhaLista->val;
        minhaLista = minhaLista->next;
        return x;
    }
    
    int top() {
        return minhaLista->val;
    }
    
    bool empty() {
        return minhaLista == nullptr;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

