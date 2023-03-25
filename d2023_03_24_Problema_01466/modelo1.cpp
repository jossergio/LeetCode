class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        map<int, vector<int>> dePara;
        map<int, vector<int>> paraDe;
        for (auto con: connections) {
            dePara [con [0]].push_back (con[1]);
            paraDe [con [1]].push_back (con[0]);
        }
        stack<int> pilha;
        vector<bool> visitados = vector (n, false); // Por conta do modelo de árvore, citado no problema
        pilha.push (0); // Usará como referência inicial
        int resposta = 0;
        while (!pilha.empty ()) {
            int proximo = pilha.top ();
            pilha.pop ();
            visitados [proximo] = true;
            for (int p: dePara [proximo]) { // São os que tem que reverter
                if (!visitados [p]) {
                    resposta += 1;
                    pilha.push (p);
                }
            }
            for (int p: paraDe [proximo]) { // Só precisa empilhar, para montar caminho
                if (!visitados [p]) {
                    pilha.push (p);
                }
            }
        }
        return resposta;
    }
};

