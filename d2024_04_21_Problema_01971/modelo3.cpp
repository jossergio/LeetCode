class Solution {
private:
    bool caminhoValido (map<int, vector<int>>& mapa, int source, int destination, vector<bool>& visitados) {
        if (source == destination)
            return true;
        // else
        visitados [source] = true; // Não precisa desfazer, pois qualquer caminho servirá
        for (int p: mapa [source])
            if (!visitados [p] && caminhoValido (mapa, p, destination, visitados))
                return true;
        return false; // Passou por tudo e não localizou
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int, vector<int>> mapa;
        for (auto ponte: edges) { // Irá transformar em um hash de matrizes de pontes
            mapa [ponte [0]].push_back (ponte [1]);
            mapa [ponte [1]].push_back (ponte [0]);
        }
        vector<bool> visitados (n, false);
        return caminhoValido (mapa, source, destination, visitados);
    }
};

