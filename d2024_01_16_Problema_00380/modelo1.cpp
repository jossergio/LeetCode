class RandomizedSet {
private:
    unordered_set<int> c;
public:
    RandomizedSet() {
        // Nada a fazer
    }
    
    bool insert(int val) {
        if (c.count (val) == 0) {
            c.insert (val);
            return true;
        }
        // else
        return false;
    }
    
    bool remove(int val) {
        if (c.count (val) != 0) {
            c.erase (val);
            return true;
        }
        // else
        return false;
    }
    
    int getRandom() {
        vector<int> v (c.begin (), c.end ());
        int i = rand () % c.size (); // Só para não gerar confusão, borrando o código
        return v [i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
