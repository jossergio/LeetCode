class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int linhas = grid.size ();
        const int colunas = grid [0].size ();
        vector<int> zerosLinha (linhas, 0);
        vector<int> zerosColuna (colunas, 0);
        // Os 1's pega-se pela subtração do tamanho
        for (int i = 0; i < linhas; i += 1)
            for (int j = 0; j < colunas; j += 1)
                if (grid [i][j] == 0) {
                    zerosLinha [i] += 1;
                    zerosColuna [j] += 1;
                }
        vector<vector<int>> resposta (linhas, vector (colunas, 0));
        for (int i = 0; i < linhas; i += 1)
            for (int j = 0; j < colunas; j += 1)
                resposta [i][j] = (linhas - zerosLinha [i]) + (colunas - zerosColuna [j]) - zerosLinha [i] - zerosColuna [j];
        return resposta;
    }
};

