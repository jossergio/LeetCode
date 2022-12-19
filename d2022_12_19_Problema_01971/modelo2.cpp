class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) // Só para agilidade
            return true;
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
                return true;
            // else
            visitados [proximo] = true;
            for (int i: tabela [proximo])
                if (!visitados [i]) {
                    if (i == destination)
                        return true;
                    else
                        fila.push (i);
                }
        }
        return false;
    }
};

