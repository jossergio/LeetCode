class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int limiteX = grid.size () - 1;
        int limiteY = grid [0].size () - 1;
        cout << endl;
        int ilha = -1; // Contará o total de ilhas; conta negativamente, para não confundir com os valores originais do grid 
        int contagem = 0; // Contará quantas são isoladas
        for (int i = 1; i <= limiteX; i += 1) // Não precisa ir do início ao fim
            for (int j = 1; j <= limiteY; j += 1) // Idem
                if (grid [i][j] == 0) {
                    stack<pair<int, int>> pilha;
                    bool isolada = true;
                    pilha.push ({i, j});
                    while (!pilha.empty ()) {
                        auto [xPos, yPos] = pilha.top ();
                        pilha.pop ();
                        grid [xPos][yPos] = ilha;
                        if (xPos == 0 || yPos == 0 || xPos == limiteX || yPos == limiteY)
                            isolada = false;
                        if (xPos > 0 && grid [xPos - 1][yPos] == 0)
                            pilha.push ({xPos - 1, yPos});
                        if (yPos > 0 && grid [xPos][yPos - 1] == 0)
                            pilha.push ({xPos, yPos - 1});
                        if (xPos < grid.size () - 1 && grid [xPos + 1][yPos] == 0)
                            pilha.push ({xPos + 1, yPos});
                        if (yPos < grid [0].size () - 1 && grid [xPos][yPos + 1] == 0)
                            pilha.push ({xPos, yPos + 1});
                    }
                    if (isolada)
                        contagem += 1;
                    ilha -= 1; // Lembrar que a contagem das ilhas é netativa, para não confundir com os valores originais de grid
                }
        return contagem;
    }
};

