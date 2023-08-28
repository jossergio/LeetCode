class MyStack {
private:
    deque<int> minhaFila;
public:
    MyStack() {
        // Nada a fazer
    }
    
    void push(int x) {
        minhaFila.push_front (x);
    }
    
    int pop() {
        int x = minhaFila.front (); // Não tira o valor mais recente incluído
        minhaFila.pop_front (); // Tira o elemento do topo
        return x;
    }
    
    int top() {
        return minhaFila.front ();
    }
    
    bool empty() {
        return minhaFila.empty ();
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

