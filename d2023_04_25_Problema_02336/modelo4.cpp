class SmallestInfiniteSet {
private:
    vector<int> heap; // Manterá os números negativos, para manter uma ordem crescente
    int proximo;
    bool existe (int n) {
        for (int v: heap)
            if (n == v)
                return true;
        // else
        return false;
    }
public:
    SmallestInfiniteSet() {
        proximo = 0;
    }
    
    int popSmallest() {
        if (heap.size () == 0)
            return ++proximo;
        // else
        int retorno = heap.front ();
        pop_heap (heap.begin (), heap.end ());
        heap.pop_back ();
        return -retorno; // Atenção para a reposição para positivo!
    }
    
    void addBack(int num) {
        if (num <= proximo && !existe (-num)) {
            heap.push_back (-num); // Atenção para o negativo
            push_heap (heap.begin (), heap.end ());
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

