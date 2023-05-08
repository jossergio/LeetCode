class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int resposta = 0;
        int t = mat.size () - 1;
        for (int i = 0; i <= t; i += 1)
            resposta += (mat [i][i] + mat [i][t - i]);
        return resposta - (mat.size () % 2 == 1 ? mat [t / 2][t / 2] : 0);
    }
};

