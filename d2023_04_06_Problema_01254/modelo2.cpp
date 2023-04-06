class Solution {
private:
    void buscar (vector<vector<int>>& grid, int xPos, int yPos, int ilha, bool& isolada) {
        grid [xPos][yPos] = ilha; // Valor para indicar que não é isolada
        if (xPos == 0 || yPos == 0 || xPos == grid.size () - 1 || yPos == grid [0].size () - 1)
            isolada = false;
        if (xPos > 0 && grid [xPos - 1][yPos] == 0)
            buscar (grid, xPos - 1, yPos, ilha, isolada);
        if (yPos > 0 && grid [xPos][yPos - 1] == 0)
            buscar (grid, xPos, yPos - 1, ilha, isolada);
        if (xPos < grid.size () - 1 && grid [xPos + 1][yPos] == 0)
            buscar (grid, xPos + 1, yPos, ilha, isolada);
        if (yPos < grid [0].size () - 1 && grid [xPos][yPos + 1] == 0)
            buscar (grid, xPos, yPos + 1, ilha, isolada);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int tx = grid.size ();
        int ty = grid [0].size ();
        cout << endl;
        int ilha = 0; // Contará o total de ilhas
        int contagem = 0; // Contará quantas são isoladas
        for (int i = 1; i < tx - 1; i += 1) // Não precisa ir do início ao fim
            for (int j = 1; j < ty - 1; j += 1) // Idem
                if (grid [i][j] == 0) {
                    bool isolada = true;
                    ilha += 1;
                    buscar (grid, i, j, ilha + 5, isolada); // Valores como 0 e 1 já são do grid; contagem de ilhas começa em seis
                    if (isolada)
                        contagem += 1;
                }
        return contagem;
    }
};

