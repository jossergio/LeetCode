class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tabela = vector (m + 1, vector (n + 1, 0));
        tabela [m - 1][n] = 1; // O resto fica zerado; para uma lógica de m sendo a linha
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                tabela [i][j] = tabela [i + 1][j] + tabela [i][j + 1];
        return tabela [0][0];
    }
};

