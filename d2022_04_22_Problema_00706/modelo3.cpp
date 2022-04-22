const int limite = 100;

class MyHashMap {
private:
    array<list<pair<int, int>>, limite> meuHash;
public:
    MyHashMap() {
        meuHash.fill (list<pair<int, int>> ());
    }
    
    void put(int key, int value) {
        for (list<pair<int, int>>::iterator i = meuHash [key % limite].begin (); i != meuHash [key % limite].end (); i++)
            if (i->first == key) {
                i->second = value;
                return;
            }
        meuHash [key % limite].push_back (pair<int, int> (key, value)); // Novo
    }
    
    int get(int key) {
        for (list<pair<int, int>>::iterator i = meuHash [key % limite].begin (); i != meuHash [key % limite].end (); i++)
            if (i->first == key)
                return i->second;
        return -1;
    }
    
    void remove(int key) {
        for (list<pair<int, int>>::iterator i = meuHash [key % limite].begin (); i != meuHash [key % limite].end (); i++)
            if (i->first == key) {
                meuHash [key % limite].remove (*i);
                break;
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

