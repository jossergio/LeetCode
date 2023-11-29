class Solution {
public:
    int hammingWeight(uint32_t n) {
        int resposta = 0;
        while (n > 0) {
            if (n & 1 == 1)
                resposta += 1;
            // Continua
            n >>= 1;
        }
        return resposta;
    }
};

