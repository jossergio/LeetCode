class Solution {
private:
    void montar (vector<vector<int>>& r, map<int, set<int>>& e, vector<int>& m, int t) {
        vector<int> visitar;
        for (int bus: e [t]) {
            for (int estacao: r [bus]) {
                if (m [estacao] == -1)  { // A estaçãõ destino inicia em 0
                    m [estacao] = m [t] + 1;
                    visitar.push_back (estacao);
                } else {
                    if (m [estacao] > m [t] + 1)
                        m [estacao] = m [t] + 1;
                }
            }
        }
        for (int v: visitar) {
            montar (r, e, m, v);
        }
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, set<int>> estacoes;
        const int t = routes.size ();
        int maxEstacoes = 0;
        for (int i = 0; i < t; i += 1)
            for (int r: routes [i]) {
                estacoes [r].insert (i);
                maxEstacoes = max (maxEstacoes, r);
            }
        vector<int> memo (maxEstacoes + 1, -1); // Ajuste de 0-begin
        memo [target] = 0;
        montar (routes, estacoes, memo, target);
        return memo [source];
    }
};

