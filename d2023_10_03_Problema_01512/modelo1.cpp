class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        const int t = nums.size ();
        int resposta = 0;
        for (int i = 0; i < t; i += 1)
            for (int j = i + 1; j < t; j += 1)
                if (nums [i] == nums [j])
                    resposta += 1;
        return resposta;
    }
};

