class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int t = nums.size ();
        vector<vector<int>> resposta;
        vector<int> cont (t + 1, 0); // 1-begin; 0-out;
        for (int n: nums)
            cont [n] += 1;
        vector<int> tmp; // Será usado no laço
        while (true) {
            for (int i = 0; i <= t; i += 1) {
                if (cont [i] > 0) {
                    tmp.push_back (i);
                    cont [i] -= 1;
                }
            }
            if (tmp.empty ())
                break;
            // else
            resposta.push_back (tmp);
            tmp.clear ();
        }
        return resposta;
    }
};

