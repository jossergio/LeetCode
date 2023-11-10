class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> grafo; // Só para mostrar a ideia que tive
        set<int> unicos; // Ao final do laço abaixo, só pode ter dois: os possíveis primeiros e últimos
        for (auto a: adjacentPairs) {
            grafo [a [0]].push_back (a [1]);
            grafo [a [1]].push_back (a [0]);
            if (unicos.count (a [0]) > 0)
                unicos.erase (a [0]); // É a segunda vez que aparece; retirar
            else
                unicos.insert (a [0]);
            if (unicos.count (a [1]) > 0)
                unicos.erase (a [1]);
            else
                unicos.insert (a [1]);
        }
        int t = adjacentPairs.size () + 1;
        int atual = *unicos.begin ();
        vector<int> resposta (t);
        resposta [0] = atual;
        int previo = atual;
        atual = grafo [atual][0]; // Esse, só pode ter um
        for (int i = 1; i < t - 1; i += 1) {
            resposta [i] = atual;
            if (grafo [atual][0] != previo) {
                previo = atual;
                atual = grafo [atual][0];
            } else {
                previo = atual;
                atual = grafo [atual][1];
            }
        }
        resposta [t - 1] = atual; // O que sobrou
        return resposta;
    }
};

