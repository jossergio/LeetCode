class Solution {
private:
    void buscar (vector<vector<int>>& grid, int yPos, int xPos) {
        grid [yPos][xPos] = 0; // Só para eliminar 1s que ligam com a borda; poderia ser qualquer valor diferente de 1
        if (yPos > 0 && grid [yPos - 1][xPos] == 1)
            buscar (grid, yPos - 1, xPos);
        if (yPos < grid.size () - 1 && grid [yPos + 1][xPos] == 1)
            buscar (grid, yPos + 1, xPos);
        if (xPos > 0 && grid [yPos][xPos - 1] == 1)
            buscar (grid, yPos, xPos - 1);
        if (xPos < grid [0].size () - 1 && grid [yPos][xPos + 1] == 1)
            buscar (grid, yPos, xPos + 1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ty = grid.size () - 1, tx = grid [0].size () - 1;
        for (int i = 0; i <= ty; i += 1) {
            if (grid [i][0] == 1)
                buscar (grid, i, 0);
            if (grid [i][tx] == 1)
                buscar (grid, i, tx);
        }
        for (int j = 0; j <= tx; j += 1) {
            if (grid [0][j] == 1)
                buscar (grid, 0, j);
            if (grid [ty][j] == 1)
                buscar (grid, ty, j);
        }
        int contagem = 0;
        for (int i = 0; i <= ty; i += 1)
            for (int j = 0; j <= tx; j +=1)
                if (grid [i][j] == 1)
                    contagem += 1;
        return contagem;
    }
};

