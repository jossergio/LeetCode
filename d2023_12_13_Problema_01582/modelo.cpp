class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int linhas = mat.size ();
        const int colunas = mat [0].size ();
        unordered_map<int, vector<int>> mapa;
        vector<int> contar_linhas (colunas, 0);
        for (int i = 0; i < linhas; i += 1) {
            for (int j = 0; j < colunas; j += 1) {
                if (mat [i][j] == 1) {
                    mapa [i].push_back (j);
                    contar_linhas [j] += 1;
                }
            }
        }
        int resposta = 0;
        for (auto [m, n]: mapa) {
            if (n.size () == 1 && contar_linhas [n [0]] == 1) {
                resposta += 1;
            }
        }
        return resposta;
    }
};

