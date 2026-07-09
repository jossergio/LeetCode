class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        size_t i = 0;
        size_t j = 0;
        size_t conj = 0;
        vector<size_t> conjuntos (n, -1);
        while (j < n) {
            while (j < n && nums [j] - nums [i] <= maxDiff) {
                conjuntos [j] = conj;
                j += 1;
            }
            i += 1;
            if (i == j){
                conj += 1;
            }
        }
        size_t c = 0;
        size_t t = queries.size ();
        vector<bool> resposta (t, false);
        for (size_t i = 0; i < t; i += 1) {
            resposta [i] = conjuntos [queries [i][0]] == conjuntos [queries [i][1]];
        }
        return resposta;
    }
};
