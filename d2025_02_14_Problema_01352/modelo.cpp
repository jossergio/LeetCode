class ProductOfNumbers {
private:
    vector<unsigned long long> acumulado;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        for (int i = 0; i < acumulado.size (); i += 1) {
            acumulado [i] *= num;
        }
        acumulado.push_back (num);
    }
    
    int getProduct(int k) {
        return acumulado [acumulado.size () - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
