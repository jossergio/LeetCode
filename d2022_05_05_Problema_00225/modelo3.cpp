class MyStack {
private:
    queue<int> minhaFila;
public:
    MyStack() {
        // Nada a fazer aqui
    }
    
    void push(int x) {
        minhaFila.push (x);
        int t = minhaFila.size ();
        
        while (--t > 0) { // Esse laço faz a fila rotacionar até o penúltimo
            minhaFila.push (minhaFila.front ());
            minhaFila.pop ();
        }
    }
    
    int pop() {
        int retorno = minhaFila.front (); // pop, de C++, não retorna valor
        minhaFila.pop ();
        return retorno; // Era o topo anterior
    }
    
    int top() {
        return minhaFila.front (); // O problema diz que todas as chamadas são válidas; não precisa validar
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

