class KthLargest {
private:
    
    priority_queue<int, vector<int>, greater<int>> lista;
    int limite;
    
    void inserir (int v) {
        lista.push (v);
        if (lista.size () > limite)
            lista.pop ();
    }
    
public:
    KthLargest(int k, vector<int>& nums) {
        
        limite = k;

        for (vector<int>::iterator e = nums.begin (); e != nums.end (); e++) {
            inserir (*e);
        }

    }
    
    int add(int val) {
        inserir (val);
        return lista.top ();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

