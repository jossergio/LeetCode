class Solution {
private:
    map<char, int> buscar (unordered_map<int, vector<int>>& grafo, vector<bool>& visitados, string& colors, int atual, map<int, map<char, int>>& memo) {
        if (memo.count (atual) == 0) {
            visitados [atual] = true;
            for (auto g: grafo [atual]) {
                if (visitados [g]) {
                    memo [atual][colors [atual]] = -1;
                    return memo [atual]; // Direto
                } else {
                    map<char, int> tmp = buscar (grafo, visitados, colors, g, memo);
                    for (auto [c, v]: tmp) {
                        memo [atual][c] = max (memo [atual][c], v);
                    }
                }
            }
            memo [atual][colors [atual]] += 1; // Acrescenta o próprio atual
            visitados [atual] = false;
        }
        return memo [atual];
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> grafo;
        for (auto e: edges)
            grafo [e [0]].push_back (e [1]);
        int t = colors.size (); // colors contém o número de vértices
        int maior = 0;
        map<int, map<char, int>> memo;
        vector<bool> visitados = vector (t, false); // Usar no laço; definir aqui pouoa memória; a cada iteração, fica tudo falso
        for (int i = 0; i < t; i += 1) {
            for (auto [c, v]: buscar (grafo, visitados, colors, i, memo)) {
                if (v == -1)
                    return -1;
                // else
                maior = max (maior, v);
            }
        }
        return maior;
    }
};

