class Solution {
private:
    void buscar (vector<int>& p, int t, int i, vector<set<int>>& g) {
        for (auto n: g [i]) {
            if (p [n] == 0) {
                p [n] = t;
                buscar (p, t, n, g);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<set<int>> grafo (isConnected.size ());
        const int tamanho = isConnected.size (); // n x n
        for (int i = 0; i < tamanho; i += 1) {
            for (int j = i + 1; j < tamanho; j += 1) {
                if (isConnected [i][j] == 1) {
                    grafo [i].insert (j);
                    grafo [j].insert (i); // Vê que varre, somente, a metade
                }
            }
        }
        int total = 0; // Na realidade, um acumulador, que representa o atual
        vector<int> provincias (tamanho, 0);
        for (int i = 0; i < tamanho; i += 1) {
            if (provincias [i] == 0) { // Ainda não pertence a provìncia alguma
                total += 1;
                provincias [i] = total;
                buscar (provincias, total, i, grafo);
            }
        }
        return total;
    }
};

