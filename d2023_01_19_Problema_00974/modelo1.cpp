class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<vector<int>> tabela (nums.size () + 1, vector (nums.size (), 0));
        int contador = 0;
        for (int i = 1; i <= nums.size (); i += 1) {
            for (int j = i - 1; j < nums.size (); j += 1) {
                if (i == 1)
                    tabela [i][j] = nums [j];
                else
                    tabela [i][j] = tabela [i - 1][j - 1] + tabela [i - 1][j] - tabela [i - 2][j - 1];
                if (tabela [i][j] % k == 0)
                    contador += 1;
            }
        }
        return contador;
    }
};

