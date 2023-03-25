class Solution {
private:
    int buscar (vector<vector<int>>& conexoes, int proximo, vector<bool>& visitados) {
        visitados [proximo] = true;
        int resposta = 0;
        for (int c: conexoes [proximo])
            if (!visitados [abs (c)])
                resposta += (c > 0 ? 1 : 0) + buscar (conexoes, abs (c), visitados);
                // Positivo é sentido normal; inverterá
        return resposta;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> conexoes (n); // Guardará negativo, quando for sentido contrário
        for (auto con: connections) {
            conexoes [con [0]].push_back (con [1]); // Positivo = Sentido normal
            conexoes [con [1]].push_back (-con[0]); // Negativo = Sentido contrário
        }
        vector<bool> visitados = vector (n, false); // Por conta do modelo de árvore, citado no problema
        return buscar (conexoes, 0, visitados);
    }
};

