class Solution {
private:
    bool buscar (vector<vector<int>>& grid, int yPos, int xPos, int& contagem) {
        bool limite = false;
        if (yPos == 0 || xPos == 0 || yPos == grid.size () - 1 || xPos == grid [0].size () - 1)
            limite = true;
        contagem += 1;
        grid [yPos][xPos] = -1; // Utiliza a própria matriz como memorizador de cainhos já percorridos
        if (yPos > 0 && grid [yPos - 1][xPos] == 1)
            limite |= buscar (grid, yPos - 1, xPos, contagem);
        if (yPos < grid.size () - 1 && grid [yPos + 1][xPos] == 1)
            limite |= buscar (grid, yPos + 1, xPos, contagem);
        if (xPos > 0 && grid [yPos][xPos - 1] == 1)
            limite |= buscar (grid, yPos, xPos - 1, contagem);
        if (xPos < grid [0].size () - 1 && grid [yPos][xPos + 1] == 1)
            limite |= buscar (grid, yPos, xPos + 1, contagem);
        return limite;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int resposta = 0;
        for (int i = 0; i < grid.size (); i += 1)
            for (int j = 0; j < grid [0].size (); j += 1)
                if (grid [i][j] == 1) {
                    int contagem = 0;
                    if (!buscar (grid, i, j, contagem))
                        resposta += contagem;
                }
        return resposta;
    }
};

