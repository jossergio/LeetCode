class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> resposta;
        for (auto q: queries) {
            int tmp = arr [q [0]];
            for (int i = q [0] + 1; i <= q [1]; i += 1) tmp ^= arr [i];
            resposta.push_back (tmp);
        }
        return resposta;
    }
};

