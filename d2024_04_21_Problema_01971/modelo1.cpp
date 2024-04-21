class Solution {
private:
    bool caminhoValido (vector<vector<int>>& tabela, int source, int destination, vector<bool>& visitados) {
        if (source == destination)
            return true;
        // else
        visitados [source] = true; // Não precisa desfazer, pois qualquer caminho servirá
        for (int i: tabela [source])
            if (!visitados [i] && caminhoValido (tabela, i, destination, visitados))
                return true;
        return false; // Passou por tudo e não localizou
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> tabela (n);
        for (auto ponte: edges) { // Irá transformar em um hash de matrizes de pontes
            tabela [ponte [0]].push_back (ponte [1]);
            tabela [ponte [1]].push_back (ponte [0]);
        }
        vector<bool> visitados (n, false);
        return caminhoValido (tabela, source, destination, visitados);
    }
};

