class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> resposta;
        for (int i = 0; i < n; i += 1) {
            resposta.push_back (nums [i]);
            resposta.push_back (nums [n + i]);
        }
        return resposta;
    }
};

