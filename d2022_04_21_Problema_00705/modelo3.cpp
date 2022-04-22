const int limite = 500;
class MyHashSet {
protected:
    array<list<int>, limite> meuHash;
public:
    MyHashSet() {
        meuHash.fill (list<int> ());
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

