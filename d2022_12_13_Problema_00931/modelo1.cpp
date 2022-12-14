class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int t = matrix.size (); // Colunas
        int n = matrix.size () - 2; // 0-begin; linhas; mantém a última
        while (n >= 0) {
            matrix [n][0] = min (matrix [n][0] + matrix [n + 1][0], matrix [n][0] + matrix [n + 1][1]);
            for (int i = 1; i < t - 1; i += 1) {
                int menor = min (matrix [n][i] + matrix [n + 1][i - 1], matrix [n][i] + matrix [n + 1][i]);
                matrix [n][i] = min (menor, matrix [n][i] + matrix [n + 1][i + 1]);
            }
            matrix [n][t - 1] = min (matrix [n][t - 1] + matrix [n + 1][t - 2], matrix [n][t - 1] + matrix [n + 1][t - 1]);
            n -= 1;
        }
        for (auto i: matrix) {
            for (auto j: i)
                cout << j << " ";
            cout << endl;
        }
        return *min_element (matrix [0].begin (), matrix [0].end ());
    }
};

