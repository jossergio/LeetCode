class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int m = matrix.size ();
        const int n = matrix [0].size ();
        vector<vector<int>> resposta = vector (n, vector (m, 0));
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1)
                resposta [i][j] = matrix [j][i];
        return resposta;
    }
};

