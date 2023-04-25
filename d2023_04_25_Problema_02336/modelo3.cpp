class SmallestInfiniteSet {
private:
    vector<int> lista;
    bool existe (int n) {
        for (int v: lista)
            if (n == v)
                return true;
        // else
        return false;
    }
public:
    SmallestInfiniteSet() {
        lista.push_back (1);
    }
    
    int popSmallest() {
        int retorno = lista [0]; // lista nunca é vazia
        if (lista.size () == 1) {
            lista.pop_back (); // Tira o único elemento
            lista.push_back (retorno + 1); // E repõe o próximo
        } else { // Só pode ser maior que zero
            lista [0] = lista.back (); // Joga o último elemento no início
            lista.pop_back (); // Tira o último elemento, que foi para o início
            sort (lista.begin (), lista.end ());
        }
        return retorno;
    }
    
    void addBack(int num) {
        if ((!(num >= lista.back ())) && !existe (num)) {
            lista.push_back (num);
            sort (lista.begin (), lista.end ());
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

