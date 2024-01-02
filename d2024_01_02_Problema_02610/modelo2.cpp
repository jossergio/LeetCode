class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int t = nums.size ();
        vector<vector<int>> resposta;
        map<int, int> cont;
        for (int n: nums)
            cont [n] += 1;
        vector<int> tmp; // Será usado no laço
        while (true) {
            for (auto& [i, v]: cont) {
                if (v > 0) {
                    tmp.push_back (i);
                    v -= 1;
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

