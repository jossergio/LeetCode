class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> conexoes (n); // Guardará negativo, quando for sentido contrário
        for (auto con: connections) {
            conexoes [con [0]].push_back (con [1]); // Positivo = Sentido normal
            conexoes [con [1]].push_back (-con[0]); // Negativo = Sentido contrário
        }
        stack<int> pilha;
        vector<bool> visitados = vector (n, false); // Por conta do modelo de árvore, citado no problema
        pilha.push (0); // Usará como referência inicial
        int resposta = 0;
        while (!pilha.empty ()) {
            int proximo = pilha.top ();
            pilha.pop ();
            visitados [proximo] = true;
            for (int c: conexoes [proximo]) { // São os que tem que reverter
                if (!visitados [abs (c)]) {
                    if (c > 0) // Sentido normal, inverte
                        resposta += 1;
                    pilha.push (abs (c)); // Para tirar o sinal
                }
            }
        }
        return resposta;
    }
};

