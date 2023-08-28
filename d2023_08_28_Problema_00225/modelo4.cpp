class MyStack {
private:
    queue<int> minhaFila;
public:
    MyStack() {
        // Nada a fazer
    }
    
    void push(int x) {
        minhaFila.push (x);
    }
    
    int pop() {
        queue<int> tmp;
        while (minhaFila.size () > 1) {
            tmp.push (minhaFila.front ());
            minhaFila.pop ();
        }
        int x = minhaFila.front (); // Deve ter sobrado um
        minhaFila.pop (); // Tira o único que restou
        while (!tmp.empty ()) {
            minhaFila.push (tmp.front ());
            tmp.pop ();
        }
        return x;
    }
    
    int top() {
        return minhaFila.back (); // Já que tem, vamos aproveitar
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

