const int limite = 100;
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
        // Atribuir gera nova ocupação de memória, gerando um novo objeto
        // Então, reordeno a lista da chave e passo para um vetor
        // array não tem construtor
        
        
        int tabela = key % limite; // Irei usar várias vezes
        
        if (meuHash [tabela].empty ())
            return false; // Só para adiantar
        
        meuHash [tabela].sort ();
        
        vector<int> elementos (meuHash [tabela].begin (), meuHash [tabela].end ());
        
        int i = 0, j = elementos.size () - 1;
        
        while (i <= j) {
            
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

