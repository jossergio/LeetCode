class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long contador = 0;
        long long acumulado = 0; // Será a resposta
        long long passo = 1;
        for (int n: nums) {
            if (n == 0) {
                contador += passo;
                passo += 1;
            } else {
                acumulado += contador;
                contador = 0;
                passo = 1;
            }
        }
        return acumulado + contador;
    }
};

