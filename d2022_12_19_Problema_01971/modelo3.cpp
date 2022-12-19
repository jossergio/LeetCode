class Solution {
private:
    bool caminhoValido (vector<vector<int>>& tabela, int source, int destination, vector<bool>& visitados) {
        visitados [source] = true; // Por memoization, jamais retornará a false
        vector<int> proximos; // Caso não encontre na vizinhança, forma uma lista para os próximos
        for (int i: tabela [source])
            if (i == destination) {
                return true;
            } else {
                if (!visitados [i])
                    proximos.push_back (i);
            }
        for (int i: proximos) // Contem só os da vizinhana e que não já foram visitados
            if (caminhoValido (tabela, i, destination, visitados))
                return true;
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) // Melhor só testar o primeiro, aqui
            return true;
        vector<vector<int>> tabela (n);
        for (auto ponte: edges) { // Irá transformar em um hash de matrizes de pontes
            tabela [ponte [0]].push_back (ponte [1]);
            tabela [ponte [1]].push_back (ponte [0]);
        }
        vector<bool> visitados (n, false);
        return caminhoValido (tabela, source, destination, visitados);
    }
};

