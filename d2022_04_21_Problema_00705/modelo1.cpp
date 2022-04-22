const int limite = 1000;
class MyHashSet {
protected:
    vector<list<int>> meuHash;
public:
    MyHashSet() {
        for (int i = 0; i < limite; i++)
            meuHash.push_back (list<int> ());
    }
    
    void add(int key) {
        meuHash [key % limite].push_back (key);
    }
    
    void remove(int key) {
        meuHash [key % limite].remove (key);
    }
    
    bool contains(int key) {
        for (list<int>::iterator i = meuHash [key % limite].begin (); i != meuHash [key % limite].end (); i++)
            if (key == *i)
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

