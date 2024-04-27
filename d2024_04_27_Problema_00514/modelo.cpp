class Solution {
private:
    int buscar (int p, int k, string& ring, string& key, map<char, vector<int>>& mapa, map<pair<int, int>, int>& memo) {
        if (k == key.size ()) // Chegou ao final
            return 0;
        // else
        int menor = INT_MAX; // Não gosto de utilizar isso, mas usei
        if (memo.count ({k, p}) > 0)
            return memo [{k, p}];
        if (ring [p] == key [k]) {
            menor = 1 + buscar (p, k + 1, ring, key, mapa, memo); // Aperta o botão e segue para o próximo
        } else {
            for (int i: mapa [key [k]]) {
                int rotacao; // Qualquer valor, aqui; será definido abaixo
                if (p > i) {
                    int tmp1 = p - i; // Só para separar e melhor visualizar
                    int tmp2 = ring.size () - p + i;
                    rotacao = min (tmp1, tmp2);
                } else { // Obs.: não podem ser iguais, pois, aqui, ring [p] != key [k]
                    int tmp1 = i - p;
                    int tmp2 = ring.size () - i + p;
                    rotacao = min (tmp1, tmp2);
                }
                menor = min (menor, rotacao + buscar (i, k, ring, key, mapa, memo));
            }
        }
        return memo [{k, p}] = menor;
    }
public:
    int findRotateSteps(string ring, string key) {
        map<char, vector<int>> mapa;
        map<pair<int, int>, int> memo;
        for (int i = 0; i < ring.size (); i += 1)
            mapa [ring [i]].push_back (i);
        return buscar (0, 0, ring, key, mapa, memo);
    }
};

