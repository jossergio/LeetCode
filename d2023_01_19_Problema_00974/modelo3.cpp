class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> restos;
        int modulo = 0;
        int contador = 0;
        restos [0] = 1;
        for (auto num: nums) {
            modulo = (modulo + num % k + k) % k; // Livra os negativos
            contador += restos [modulo];
            restos [modulo] += 1;
        }
        return contador;
    }
};

