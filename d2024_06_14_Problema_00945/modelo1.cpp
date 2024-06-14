class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        const int t = nums.size ();
        sort (nums.begin (), nums.end ());
        int resposta = 0;
        for (int i = 0; i < t; i += 1) {
            for (int j = i + 1; j < t && nums [j] == nums [i]; j += 1) {
                nums [j] += 1;
                resposta += 1;
            }
        }
        return resposta;
    }
};

