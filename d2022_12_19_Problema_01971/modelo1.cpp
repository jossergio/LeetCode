class Solution {
private:
    bool caminhoValido (int n, vector<vector<int>>& tabela, int source, int destination, vector<bool>& visitados) {
        visitados [source] = true; // Por memoization, jamais retornará a false
        for (auto i: tabela [source])
            if (i == destination || (!visitados [i] && caminhoValido (n, tabela, i, destination, visitados)))
                return true;
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) // Agiliza e livra de uma pegadinha do LeetCode
            return true;
        vector<vector<int>> tabela (n);
        for (auto ponte: edges) { // Irá transformar em um hash de matrizes de pontes
            tabela [ponte [0]].push_back (ponte [1]);
            tabela [ponte [1]].push_back (ponte [0]);
        }
        vector<bool> visitados (n, false);
        return caminhoValido (n, tabela, source, destination, visitados);
    }
};

