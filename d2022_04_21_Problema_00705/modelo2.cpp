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
        meuHash [key % limite].sort ();
    }
    
    void remove(int key) {
        meuHash [key % limite].remove (key);
        // Não precisa reordenar
    }
    
    bool contains(int key) {
        // É pra essa função, nesse formato, que se deve manter as listas ordenadas
        // Atribuir gera nova ocupação de memória, gerando um novo objeto
        // Por isso, passei direto a um vector, em vez de gerar um list intermediário
        
        int tabela = key % limite; // Irei usar várias vezes
        
        if (meuHash [tabela].empty ())
            return false; // Só para adiantar
        
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

