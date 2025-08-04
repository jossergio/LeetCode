class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        size_t i = 0;
        const size_t t = fruits.size ();
        unordered_map<int, size_t> bases;
        pair<int, int> pontos; // De posição
        int maximo = 0;
        pontos.first = fruits [i];
        bases [pontos.first] = i;
        while (i < t && fruits [i] == pontos.first) {
            maximo += 1;
            i += 1;
        }
        if (i == t) return maximo; // Só tinha um tipo
        // else
        pontos.second = fruits [i];
        bases [pontos.second] = i;
        int resposta = maximo;
        while (i < t && fruits [i] == pontos.second) {
            maximo += 1;
            resposta = max (resposta, maximo);
            i += 1;
            if (i < t && fruits [i] != pontos.second) {
                if (fruits [i] == pontos.first) {
                    bases [pontos.first] = i;
                } else {
                    maximo = i - bases [pontos.second];
                    bases [fruits [i]] = i;
                }
                pontos.first = pontos.second;
                pontos.second = fruits [i];
            }
        }
        return resposta;
    }
};
