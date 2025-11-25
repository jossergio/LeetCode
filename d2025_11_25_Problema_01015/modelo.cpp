class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 0 || k % 2 == 0 || k % 5 == 0) { // Os pares (e seguem os 4, 6 e 8), os cinco e os dez
            return -1; // Já para garantir; no final, mesma coisa
        }
        int resto = 0;
        for (int tamanho = 1; tamanho <= k; tamanho++) {
            resto = (resto * 10 + 1) % k;
            if (resto == 0)
                return tamanho;
        }
        return -1;
    }
};
