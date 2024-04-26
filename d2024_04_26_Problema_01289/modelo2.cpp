class Solution {
private:
    int buscar (vector<vector<int>>& memo, vector<vector<bool>>& calculados, vector<vector<int>>& grid, int nivel, int p) {
        if (nivel == grid.size () - 1)
            return grid [nivel][p]; // Não entra no memo
        // else
        if (!calculados [nivel][p]) {
            if (p == 0)  // Como é n x n, e a primeira linha dessa função já descartou n == 1...
                memo [nivel][p] = grid [nivel][p] + buscar (memo, calculados, grid, nivel + 1, 1); // Inicializa com o segundo
            else
                memo [nivel][p] = grid [nivel][p] + buscar (memo, calculados, grid, nivel + 1, 0); // Inicializa com o primeiro
            for (int i = 0; i < grid [nivel].size (); i += 1) {
                if (i == p) // Não calcula a mesma coluna adjacente
                   continue ;
                memo [nivel][p] = min (memo [nivel][p], grid [nivel][p] + buscar (memo, calculados, grid, nivel + 1, i));
            }
            calculados [nivel][p] = true;
        }
        return memo [nivel][p];
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int t = grid.size (); // É n x n; serve para ambos
        vector<vector<int>> memo (t, vector<int> (t, 0));
        vector<vector<bool>> calculados (t, vector<bool> (t, false));
        int resposta = buscar (memo, calculados, grid, 0, 0); // Define, diretamente, essa posição
        for (int i = 1; i < t; i += 1)
            resposta = min (resposta, buscar (memo, calculados, grid, 0, i));
        return resposta;
    }
};

