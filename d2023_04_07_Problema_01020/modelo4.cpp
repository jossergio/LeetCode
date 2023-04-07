class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ty = grid.size () - 1, tx = grid [0].size () - 1;
        int resposta = 0;
        // As variáveis abaixo são para serem utilizadas no laço; evitar ficar alocando a cada iteração
        int contagem;
        int borda;
        stack<pair<int, int>> pilha;
        for (int i = 0; i <= ty; i += 1)
            for (int j = 0; j <= tx; j += 1)
                if (grid [i][j] == 1) {
                    contagem = 0;
                    borda = false; // Pressupõe
                    pilha.push ({i, j}); // Sempre estará vazia no início de cada iteração
                    while (!pilha.empty ()) {
                        auto [yPos, xPos] = pilha.top ();
                        pilha.pop ();
                        if (grid [yPos][xPos] != 1)
                            continue; // Pode ter mudado, por outro empilhamento
                        contagem += 1;
                        borda |= yPos == 0 || yPos == ty || xPos == 0 || xPos == tx;
                        grid [yPos][xPos] = -1; // Utiliza a própria matriz para memorizar por onde passou; poderia ser qualquer valor diferente de 1
                        if (yPos > 0 && grid [yPos - 1][xPos] == 1)
                            pilha.push ({yPos - 1, xPos});
                        if (yPos < ty && grid [yPos + 1][xPos] == 1)
                            pilha.push ({yPos + 1, xPos});
                        if (xPos > 0 && grid [yPos][xPos - 1] == 1)
                            pilha.push ({yPos, xPos - 1});
                        if (xPos < tx && grid [yPos][xPos + 1] == 1)
                            pilha.push ({yPos, xPos + 1});
                    }
                    if (!borda)
                        resposta += contagem;
                }
        return resposta;
    }
};

