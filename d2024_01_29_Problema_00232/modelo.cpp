class MyQueue {
private:
    stack<int> pilha; // A segunda pilha só é utilizada em um momento
    int proximo; // Para o peek
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (pilha.empty ())
            proximo = x; // Para o peek
        pilha.push (x);
    }
    
    int pop() {
        // Não há necessidade de testar, segundo o enunciado do problema
        int tmp = proximo;
        stack<int> auxiliar;
        while (!pilha.empty ()) {
            auxiliar.push (pilha.top ());
            pilha.pop ();
        }
        auxiliar.pop (); // Só retira
        if (!auxiliar.empty ())
            proximo = auxiliar.top (); // Atualiza o peek
        while (!auxiliar.empty ()) { // Retorna tudo para pilha 0, se houver
            pilha.push (auxiliar.top ());
            auxiliar.pop ();
        }
        return tmp;
    }
    
    int peek() {
        // Não há necessidade de testar, segundo o enunciado do problema
        return proximo;
    }
    
    bool empty() {
        return pilha.empty ();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 
