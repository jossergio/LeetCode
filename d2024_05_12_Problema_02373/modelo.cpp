class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        function<int (int, int)> maior = [&grid] (int y, int x) -> int {
            int resposta = grid [y][x]; // Por definição
            for (int i = y - 1; i <= y + 1; i += 1)
                for (int j = x - 1; j <= x + 1; j += 1)
                    resposta = max (resposta, grid [i][j]);
            return resposta;
        }; // maior

        const int t = grid.size () - 2; // A dimeisão da resposta é reduzida
        vector<vector<int>> resposta (t, vector (t, 0));
        for (int i = 1; i <= t; i += 1) // Atenção para o cálculo das dimensões da resposta
            for (int j = 1; j <= t; j += 1) // Idem
                resposta [i - 1][j - 1] = maior (i, j);
        return resposta;
    }
};

