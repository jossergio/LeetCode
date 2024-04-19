class Solution {
private:
    void visitar (vector<vector<char>>& tabuleiro, int linha, int coluna) {
        
        if (linha < 0 || linha >= tabuleiro.size () || coluna < 0 || coluna >= tabuleiro [0].size () || tabuleiro [linha][coluna] == '0')
            return;
        
        tabuleiro [linha][coluna] = '0';
        visitar (tabuleiro, linha - 1, coluna);
        visitar (tabuleiro, linha + 1, coluna);
        visitar (tabuleiro, linha, coluna - 1);
        visitar (tabuleiro, linha, coluna + 1);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int resposta = 0;
        
        for (int l = 0; l < grid.size (); l++)
            for (int c = 0; c < grid [0].size (); c++)
                if (grid [l][c] == '1') {
                    visitar (grid, l, c);
                    resposta++;
                }
        
        return resposta;
    }
};

