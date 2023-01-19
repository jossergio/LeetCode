class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> auxiliar (nums.size ());
        auxiliar [0] = nums [0];
        int contador = 0;
        for (int i = 0; i < nums.size (); i += 1) {
            if (i == 0)
                auxiliar [0] = nums [0];
            else
                auxiliar [i] = auxiliar [i - 1] + nums [i];
            if (auxiliar [i] % k == 0)
                contador += 1;
            for (int j = 0; j < i; j += 1)
                if ((auxiliar [i] - auxiliar [j]) % k == 0)
                    contador += 1;
        }
        return contador;
    }
};

