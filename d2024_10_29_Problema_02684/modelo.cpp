class Solution {
private:
    int buscar (vector<vector<int>>& grid, vector<vector<int>>& memo, int i, int j) {
        auto pegar = [&grid] (int y, int x) -> int {
            if (y < 0 || y >= grid.size () || x >= grid [0].size ()) return 0; // para não ter possibilidade de ser maior que o teste; bateu no final
            else return grid [y][x];
        };
        if (memo [i][j] == -1) { // Ainda não calculado
            memo [i][j] = 0;
            if (grid [i][j] < pegar (i - 1, j + 1)) memo [i][j] = max (memo [i][j], 1 + buscar (grid, memo, i - 1, j + 1));
            if (grid [i][j] < pegar (i, j + 1)) memo [i][j] = max (memo [i][j], 1 + buscar (grid, memo, i, j + 1));
            if (grid [i][j] < pegar (i + 1, j + 1)) memo [i][j] = max (memo [i][j], 1 + buscar (grid, memo, i + 1, j + 1));
        }
        return memo [i][j];
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> memo (grid.size (), vector<int> (grid [0].size (), -1));
        int resposta = 0;
        for (int i = 0; i < grid.size (); i += 1) resposta = max (resposta, buscar (grid, memo, i, 0));
        return resposta;
    }
};

