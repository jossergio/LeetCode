class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        map<int, vector<pair<int, int>>> conexoes; // O segundo parâmetro é a direção
        for (auto con: connections) {
            conexoes [con [0]].push_back ({con[1], 1}); // 1 = Sentido normal
            conexoes [con [1]].push_back ({con[0], -1}); // -1 = Sentido contrário
        }
        stack<int> pilha;
        vector<bool> visitados = vector (n, false); // Por conta do modelo de árvore, citado no problema
        pilha.push (0); // Usará como referência inicial
        int resposta = 0;
        while (!pilha.empty ()) {
            int proximo = pilha.top ();
            pilha.pop ();
            visitados [proximo] = true;
            for (auto c: conexoes [proximo]) { // São os que tem que reverter
                if (!visitados [c.first]) {
                    if (c.second == 1) // Sentido normal, inverte
                        resposta += 1;
                    pilha.push (c.first);
                }
            }
        }
        return resposta;
    }
};

