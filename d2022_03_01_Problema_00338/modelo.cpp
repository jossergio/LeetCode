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
        
        vector<int> resposta;
        
        for (int i = 0; i <= n; i++) {
            resposta.push_back (contar (i));
        }
        
        return resposta;
    }
};

