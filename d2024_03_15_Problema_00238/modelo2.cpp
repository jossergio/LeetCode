class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int t = nums.size ();
        vector<int> resposta (t, 0);
        int produto = 1;
        int contarZeros = 0;
        for (int v: nums) {
            if (v != 0) {
                produto *= v;
            } else {
                contarZeros += 1;
            }
        }
        for (int i = 0; i < t; i += 1) {
            if (nums [i] == 0) {
                if (contarZeros > 1)
                    resposta [i] = 0;
                else
                    resposta [i] = produto;
            } else {
                if (contarZeros > 0)
                    resposta [i] = 0;
                else
                    resposta [i] = produto / nums [i];
            }
        }
        return resposta;
    }
};

