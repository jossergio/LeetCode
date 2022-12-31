class Solution {
private:
    void buscar (vector<vector<int>> &grid, int y, int x, int totalVazios, int &resposta) {
        if (y < 0 || y >= grid.size () || x < 0 || x >= grid [0].size ()) // Preferi fazer o teste aqui
            return;
        switch (grid [y][x]) {
            case 0:
                grid [y][x] = -2; // Marca que já passou por aqui nessa caminihada
                buscar (grid, y + 1, x, totalVazios - 1, resposta);
                buscar (grid, y - 1, x, totalVazios - 1, resposta);
                buscar (grid, y, x + 1, totalVazios - 1, resposta);
                buscar (grid, y, x - 1, totalVazios - 1, resposta);
                grid [y][x] = 0; // Restaura; grid vem por referência
                break;
            case 2:
                if (grid [y][x] == 2 && totalVazios == 0)
                    resposta += 1;
                break;
            // Não precisa para os demais
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int totalVazios = 0; // Para saber quandos vazios existem, marcando o final da linha
        int inicial_Y;
        int inicial_X;
        for (int i = 0; i < grid.size (); i++)
            for (int j = 0; j < grid [0].size (); j++) {
                switch (grid [i][j]) {
                    case 1: inicial_Y = i; inicial_X = j; break;
                    case 0: totalVazios += 1; break;
                    // Não há necessidade para os demais casos
                }
            }
        int resposta = 0;
        buscar (grid, inicial_Y + 1, inicial_X, totalVazios, resposta);
        buscar (grid, inicial_Y - 1, inicial_X, totalVazios, resposta);
        buscar (grid, inicial_Y, inicial_X + 1, totalVazios, resposta);
        buscar (grid, inicial_Y, inicial_X - 1, totalVazios, resposta);
        // O código acima poderia ter ficado na função, no switch, mas, considerei que ficari mais complexo
        return resposta;
    }
};

