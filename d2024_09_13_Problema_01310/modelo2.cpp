class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size (); i += 1) arr [i] ^= arr [i - 1];
        vector<int> resposta;
        for (auto q: queries) {
            if (q [0] == 0) resposta.push_back (arr [q [1]]);
            else resposta.push_back (arr [q [1]] ^ arr [q [0] - 1]);
        }
        return resposta;
    }
};

