class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> resposta = vector (nums.size (), -1);
        const int base = 2 * k + 1; // Quantidade de elementos por vez
        if (base > nums.size ()) // Há mais valores que nums
            return resposta; // Não há o que fazer
        long soma = 0;
        for (int i = 0; i < base; i += 1)
            soma += nums [i];
        resposta [k] = soma / base;
        for (int i = k + 1; i < nums.size () - k; i += 1) {
            soma += nums [i + k] - nums [i - k - 1];
            resposta [i] = soma / base;
        }
        return resposta;
    }
};

