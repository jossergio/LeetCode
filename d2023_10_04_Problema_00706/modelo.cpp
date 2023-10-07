const int limite = 100;

class MyHashMap {
private:
    array <unordered_map <int, int>, limite> meuHash;
public:
    MyHashMap() {
        meuHash.fill (unordered_map <int, int> ());
    }
    
    void put(int key, int value) {
        meuHash [key % limite][key] = value;
    }
    
    int get(int key) {
        try {
            return meuHash [key % limite].at (key);
        } 
        catch (const out_of_range& e) {
            return -1;
        }
        return -1; // Nem deve chegar aqui
    }
    
    void remove(int key) {
        meuHash [key % limite].erase (key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

