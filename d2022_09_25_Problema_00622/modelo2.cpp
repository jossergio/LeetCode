class MyCircularQueue {
private:
    int* fila;
    bool cheio;
    int inicio, fim, tamanho;
public:
    MyCircularQueue(int k) {
        // Mais compreensível iniciar assim que por definição do construtor
        cheio = false;
        inicio = 0;
        fim = 0;
        fila = new int [k];
        tamanho = k;
    }
    
    bool enQueue(int value) {
        
        if (cheio)
            return false;
        // else
        
        fila [fim] = value;
        
        fim = (fim + 1) % tamanho;
        
        if (fim == inicio)
            cheio = true;
        
        return true;
    }
    
    bool deQueue() {
        
        if (inicio == fim && !(cheio))
            return false;
        // else
        
        inicio = (inicio + 1) % tamanho;
        
        cheio = false; // Indiferente
        
        return true;
    }
    
    int Front() {
        
        if (inicio == fim && !(cheio))
            return -1;
        // else
        
        return fila [inicio];
    }
    
    int Rear() {
        if (inicio == fim && !(cheio))
            return -1;
        // else
        
        if (fim == 0)
            return fila [tamanho - 1];
        // else
        
        return fila [fim - 1];
    }
    
    bool isEmpty() {
        return (inicio == fim && !(cheio));
    }
    
    bool isFull() {
        return cheio;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

