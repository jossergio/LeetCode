class RandomizedSet {
private:
    vector<int> conjunto;
    int efetivo = 0; // Conterá o tamanho efetivo do vetor
public:
    RandomizedSet() {
        // Nada a fazer
    }
    
    bool insert(int val) {
        for (int i = 0; i < efetivo; i++)
            if (conjunto [i] == val)
                return false;
        if (efetivo < conjunto.size ())
            conjunto [efetivo] = val;
        else // Só pode ser igual e coloca no final
            conjunto.push_back (val);
        efetivo += 1;
        return true;
    }
    
    bool remove(int val) {
        for (int i = 0; i < efetivo; i++)
            if (conjunto [i] == val) {
                conjunto [i] = conjunto [--efetivo]; // Joga o último no lugar do atual; e decrementa
                return true;
            }
        return false;
    }
    
    int getRandom() {
        return conjunto [rand () % efetivo];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

