class MyStack {
private:
    queue<int> minhaFila;
    int topo = 0;
public:
    MyStack() {
        // Nada a fazer aqui
    }
    
    void push(int x) {
        minhaFila.push (x);
        topo = x; // Para agiliar chamadas a top
    }
    
    int pop() {
        
        int retorno = topo;
        int t = minhaFila.size ();
        
        while (--t > 0) { // Esse laço faz a fila rotacionar até o penúltimo
            topo = minhaFila.front (); // Já garante o próximo; chamadas válidas
            minhaFila.push (minhaFila.front ());
            minhaFila.pop ();
        }
        
        minhaFila.pop (); // Retira
        
        return retorno; // Era o topo anterior
        
    }
    
    int top() {
        return topo; // O problema diz que todas as chamadas são válidas; não precisa validar
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

