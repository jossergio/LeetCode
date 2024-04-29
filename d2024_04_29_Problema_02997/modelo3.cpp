class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int acumulado = 0;
        for (int i: nums)
            acumulado ^= i;
        int base = 1; // Deslocara shift left, para comparar cada bit no laço abaixo
        int contagem = 0;
        while (acumulado != k) {
            if ((acumulado & base) != (k & base)) {
                contagem += 1;
                acumulado ^= base;
            }
            base <<= 1;
        }
        return contagem;
    }
};

