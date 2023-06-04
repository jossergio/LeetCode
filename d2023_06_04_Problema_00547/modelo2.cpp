class Solution {
private:
    void buscar (vector<int>& p, int t, int i, vector<vector<int>>& c) {
        for (int j = 0; j < c.size (); j += 1) {
            if (c [i][j] == 1 && p [j] == 0) {
                p [j] = t;
                buscar (p, t, j, c);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int total = 0; // Na realidade, um acumulador, que representa o atual
        const int tamanho = isConnected.size ();
        vector<int> provincias (tamanho, 0);
        for (int i = 0; i < tamanho; i += 1) {
            if (provincias [i] == 0) { // Ainda não pertence a provìncia alguma
                total += 1;
                provincias [i] = total;
                buscar (provincias, total, i, isConnected);
            }
        }
        return total;
    }
};

