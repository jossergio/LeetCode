class Solution {
public:
    int hammingWeight(uint32_t n) {
        int resposta = 0;
        while (n > 0) {
            if (n % 2 != 0)
                resposta += 1;
            // Continua
            n /= 2;
        }
        return resposta;
    }
};

