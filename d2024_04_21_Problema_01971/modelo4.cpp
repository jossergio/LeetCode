class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> tabela (n);
        for (auto ponte: edges) { // Irá transformar em um hash de matrizes de pontes
            tabela [ponte [0]].push_back (ponte [1]);
            tabela [ponte [1]].push_back (ponte [0]);
        }
        vector<bool> visitados (n, false);
        queue<int> fila;
        fila.push (source);
        while (!fila.empty ()) {
            int proximo = fila.front ();
            fila.pop ();
            if (proximo == destination)
                return true; // Chegou
            visitados [proximo] = true;
            for (int p: tabela [proximo])
                if (!visitados [p]) {
                    visitados [p] = true;
                    fila.push (p);
                }
        }
        return false; // Passou pelos caminhos possíveis e não localizou
    }
};

