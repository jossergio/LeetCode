const size_t limite = 1000;
class MyHashSet {
protected:
    vector<list<int>> meuHash = vector<list<int>> (limite, list<int> ());
public:
    MyHashSet() {

    }
    
    void add(int key) {
        meuHash [key % limite].push_back (key);
    }
    
    void remove(int key) {
        meuHash [key % limite].remove (key);
    }
    
    bool contains(int key) {
        for (auto k: meuHash [key % limite])
            if (key == k)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

