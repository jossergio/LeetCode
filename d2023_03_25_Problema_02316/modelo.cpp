class Solution {
private:
    int pegarLivre (vector<bool> v, int proximo) {
        for (int i = proximo; i < v.size (); i += 1)
            if (! v [i])
                return i;
        return -1;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        if (edges.size () == 0) { // Eu não queria fazer isso, mas, tive
            long long resposta = 0;
            while (n > 1) {
                resposta += (long long) --n;
            }
            return resposta;
        }
        vector<bool>visitados = vector (n, false);
        vector<long long> grupos;
        vector<vector<int>> adjacencias (n);
        for (auto e: edges) {
            adjacencias [e [0]].push_back (e [1]);
            adjacencias [e [1]].push_back (e [0]);
        }
        long long total = 0;
        int proximo = pegarLivre (visitados, 0);
        while (proximo != -1) {
            stack<int> pilha;
            pilha.push (proximo);
            vector<int> montar;
            while (!pilha.empty ()) {
                int atual = pilha.top ();
                pilha.pop ();
                if (!visitados [atual]) {
                    visitados [atual] = true;
                    montar.push_back (atual);
                    for (int p: adjacencias [atual]) {
                        if (!visitados [p])
                            pilha.push (p);
                    }
                }
            }
            long long tmp = (long long) montar.size ();
            for (int v: grupos)
                total += v * tmp;
            grupos.push_back (tmp);
            proximo = pegarLivre (visitados, proximo);
        }
        return total;
    }
};

