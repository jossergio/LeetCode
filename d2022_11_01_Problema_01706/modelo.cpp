class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> resposta (grid [0].size ());
        for (int k = 0; k < resposta.size (); k++)
            resposta [k] = k;
        int linhas = grid.size ();
        int colunas = grid [0].size ();
        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                if (resposta [j] >= 0) {
                    if ((resposta [j] > 0 && grid [i][resposta [j]] == -1 && grid [i][resposta [j] - 1] == 1) || (resposta [j] == 0 && grid [i][j] == -1)) {
                        resposta [j] = -1;
                        continue;
                    }
                    if ((resposta [j] < colunas - 1 && grid [i][resposta [j]] == 1 && grid [i][resposta [j] + 1] == -1) || (resposta [j] == colunas - 1 && grid [i][resposta [j]] == 1)){
                        resposta [j] = -1;
                        continue;
                    }
                    resposta [j] += grid [i][resposta [j]];
                }
        return resposta;
    }
};

