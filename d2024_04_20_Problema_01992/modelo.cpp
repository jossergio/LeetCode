class Solution {
private:
vector<int> montar (vector<vector<int>>& terra, int i, int j) {
    vector<int> retorno (4);
    retorno [0] = i;
    retorno [1] = j;
    int final_i = i; // Tem que ter um início
    int final_j = j; // Idem
    const int ti = terra.size ();
    const int tj = terra [0].size ();
    for (int ii = i; ii < ti; ii += 1) {
        if (terra [ii][j] != 1) // Sim, j
            break;
        final_i = ii;
        for (int jj = j; jj < tj; jj += 1) {
            if (terra [ii][jj] != 1)
                break;
            final_j = jj;
            terra [ii][jj] = 0; // Para o caso de visitar em outros testes
        }
    }
    retorno [2] = final_i;
    retorno [3] = final_j;
    return retorno;
}
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> resposta;
        const int ty = land.size ();
        const int tx = land [0].size ();
        for (int i = 0; i < ty; i += 1)
            for (int j = 0; j < tx; j += 1)
                if (land [i][j] == 1)
                    resposta.push_back (montar (land, i, j));
        return resposta;
    }
};

