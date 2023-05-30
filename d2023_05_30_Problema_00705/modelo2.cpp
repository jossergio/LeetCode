const size_t limite = 100;
class MyHashSet {
protected:
    array<pair<bool, list<int>>, limite> meuHash;
public:
    MyHashSet() {
        meuHash.fill (pair<bool, list<int>> (true, list<int> ()));
    }
    
    void add(int key) {
        meuHash [key % limite].second.push_back (key);
        meuHash [key % limite].first = false; // Não está ordenado
    }
    
    void remove(int key) {
        meuHash [key % limite].second.remove (key);
        // Não faz diferena estar ordenado ou não
    }
    
    bool contains(int key) {
        int tabela = key % limite; // Irei usar várias vezes
        if (meuHash [tabela].second.empty ())
            return false; // Só para adiantar
        if (!meuHash [tabela].first) { // Não está ordenado
            meuHash [tabela].second.sort (); // E que faremos uma busca binária
            meuHash [tabela].first = true; // Esta ordenado
        }
        vector<int> elementos (meuHash [tabela].second.begin (), meuHash [tabela].second.end ());
        int i = 0, j = elementos.size () - 1;
        while (i <= j) { // Faz uma busca binária
            int meio = (i + j) / 2;
            if (elementos [meio] == key)
                return true;
            if (key < elementos [meio])
                j = meio - 1;
            else
                i = meio + 1;
        }
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

