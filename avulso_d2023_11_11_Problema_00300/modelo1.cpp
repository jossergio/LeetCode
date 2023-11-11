class Solution {
private:
    int buscar (int i, vector<int>& nums, vector<int>& memo) {
        if (memo [i] == -1) {
            int maior = 1; // O próprio
            for (int j = i + 1; j < nums.size (); j += 1)
                if (nums [j] > nums [i])
                    maior = max (maior, 1 + buscar (j, nums, memo));
            memo [i] = maior;
        }
        return memo [i];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo (nums.size () + 1, -1);
        memo [nums.size ()] = 0;
        int resposta = 0;
        for (int i = nums.size () - 1; i >=0; i -= 1)
            resposta = max (resposta, buscar (i, nums, memo));
        return resposta;
    }
};

