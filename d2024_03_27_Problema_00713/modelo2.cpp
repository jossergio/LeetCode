class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int t = nums.size ();
        int inicio = 0;
        int contador = 0;
        int acumulado = 1; // Elemento neutro da multiplicação
        for (int i = 0; i < t; i += 1) {
            acumulado *= nums [i];
            while (inicio <= i && acumulado >= k)
                acumulado /= nums [inicio++];
            contador += i - inicio + 1; // - inicio pode ser zero ou -1, também
        }
        return contador;
    }
};

