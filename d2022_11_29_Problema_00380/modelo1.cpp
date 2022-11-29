class RandomizedSet {
private:
    unordered_map<int, bool> conjunto;
public:
    RandomizedSet() {
        // Nada a fazer
    }
    
    bool insert(int val) {
        if (conjunto [val])
            return false;
        conjunto [val] = true;
        return true;
    }
    
    bool remove(int val) {
        if (conjunto [val]) {
            conjunto [val] = false;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        vector<int> tmp;
        for (auto item: conjunto)
            if (item.second)
                tmp.push_back (item.first);
        return tmp [rand () % tmp.size ()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

