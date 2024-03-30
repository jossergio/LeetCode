class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int contador = 0;
        const int t = nums.size ();
        for (int i = 0; i < t; i += 1) {
            int acumulado = 1; // Elemento neutro da multiplicação
            for (int j = i; j < t; j += 1) {
                acumulado *= nums [j];
                if (acumulado < k)
                    contador += 1;
                else
                    break; // A partir daqui, será sempre maior
            }
        }
        return contador;
    }
};

