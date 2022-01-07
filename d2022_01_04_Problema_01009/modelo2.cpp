class Solution {
public:
    int bitwiseComplement(int n) {
        int soma = 1, tmp = n;
        // soma: n + complemento = 1111...
        while ((tmp >>= 1) != 0)
            soma = (soma << 1) + 1;
        return soma - n; // Gera-se a soma; e subtrai, para extrair o complemento
    }
};

