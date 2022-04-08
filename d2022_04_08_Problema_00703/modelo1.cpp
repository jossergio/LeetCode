class KthLargest {
private:
    
    vector<int> lista;
    vector<int>::iterator p; // Para agilizar na alocação
    int retorno; // Manterá o valor passado por k
    
    void inserir (int i) {
        
        p = lista.begin ();
        
        while (p != lista.end () && *p > i) {
            p++;
        }
        
        if (p == lista.end ())
            lista.push_back (i);
        else
            p = lista.insert (p, i);
    }
    
public:
    KthLargest(int k, vector<int>& nums) {
        
        // Não se pode usar o insert de vector aqui, pois, tem que manter ordenado

        for (vector<int>::iterator e = nums.begin (); e != nums.end (); e++) {
            inserir (*e);
        }

        retorno = k;
        
    }
    
    int add(int val) {
        inserir (val);
        return lista [retorno - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

