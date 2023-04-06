class Solution {
private:
    void isolar (vector<vector<int>>& grid, int xPos, int yPos, int funcao) {
        // funcao: traz qual a finalidade da chamada, isolar ou contar
        // -1: isolar ilhas limitadas à borda
        // v: isolhar as demais ilhas (contador da ilha + 5)
        // Altera esse valor no grid, para registrar que já passou
        grid [xPos][yPos] = funcao; // Valor para indicar que não é isolada
        if (xPos > 0 && grid [xPos - 1][yPos] == 0)
            isolar (grid, xPos - 1, yPos, funcao);
        if (yPos > 0 && grid [xPos][yPos - 1] == 0)
            isolar (grid, xPos, yPos - 1, funcao);
        if (xPos < grid.size () - 1 && grid [xPos + 1][yPos] == 0)
            isolar (grid, xPos + 1, yPos, funcao);
        if (yPos < grid [0].size () - 1 && grid [xPos][yPos + 1] == 0)
            isolar (grid, xPos, yPos + 1, funcao);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int tx = grid.size ();
        int ty = grid [0].size ();
        cout << endl;
        for (int i = 0; i < tx; i += 1) {
            if (grid [i][0] == 0)
                isolar (grid, i, 0, -1); // Isolar fronteiras
            if (grid [i][ty - 1] == 0)
                isolar (grid, i, ty - 1, -1); // Isolar fronteiras
        }
        for (int i = 0; i < ty; i += 1) {
            if (grid [0][i] == 0)
                isolar (grid, 0, i, -1); // Isolar fronteiras
            if (grid [tx - 1][i] == 0)
                isolar (grid, tx - 1, i, -1); // Isolar fronteiras
        }
        int resposta = 0;
        for (int i = 1; i < tx - 1; i += 1) // Não precisa ir do início ao fim
            for (int j = 1; j < ty - 1; j += 1) // Idem
                if (grid [i][j] == 0) {
                    resposta += 1;
                    isolar (grid, i, j, resposta + 5); // Isolar demais ilhas
                }
        return resposta;
    }
};

