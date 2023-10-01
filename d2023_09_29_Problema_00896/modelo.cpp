class Solution {
private:
    int fSinal (int i) {
        if (i > 0)
            return 1;
        // else
        if (i < 0)
            return -1;
        return 0; // É o próprio
    }
public:
    bool isMonotonic(vector<int>& nums) {
        int t = nums.size ();
        if (t == 1) // Pois é, LeetCode
            return true; // Imediato, pois o algoritmo não trata essa situação
        int sinal = 0; // Inicialmente, neutro; LeetCode
        for (int i = 1; i < t; i += 1) {
            int nSinal = fSinal (nums [i] - nums [i - 1]);
            if (sinal == 0) { // Ainda indefinido
                if (nSinal != 0)
                    sinal = nSinal;
            } else
                if (nSinal != 0 & sinal != nSinal)
                    return false; // Situação de quebra da sequência do sinal incremental
        }
        return true; // Passou por tudo e não quebrou a sequência incremental
    }
};

