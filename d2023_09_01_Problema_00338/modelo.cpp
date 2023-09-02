class Solution {
protected:
    int contar (int n) {
        
        int resposta = 0;
        
        while (n > 0) {
            if (n & 1)
                resposta++;
            n >>= 1;
        }
        
        return resposta;
    }
public:
    vector<int> countBits(int n) {
        
        vector<int> resposta (n + 1, 0);
        
        for (int i = 0; i <= n; i++) {
            resposta [i] = contar (i);
        }
        
        return resposta;
    }
};

