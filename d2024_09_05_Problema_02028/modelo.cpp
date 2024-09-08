class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int t = rolls.size () + n;
        int soma = 0;
        for (int& v: rolls) soma += v;
        mean *= t; // Essa é a soma integral antes da média; aproveita variável
        if (soma + n > mean || soma + n * 6 < mean) return vector<int> (); //Não tem como chegar em um resultado que atenda ao esperado
        int minimo = n; // Todos sao 1
        int maximo = n * 6; // Todos sao 6
        int k = (minimo + maximo) / 2;
        while (soma + k != mean) {
            if (soma + k < mean) {
                minimo = k + 1;
            } else {
                maximo = k - 1;
            }
            k = (minimo + maximo) / 2;
        }
        vector<int> resposta (n, 1); // Inicialmente, todos são 1
        k -= n; // Já retira os usados acima
        int p = 0; // Posição sendo preenchida
        while (k > 0) { // Vai jogar o resto
            if (resposta [p] == 6) p += 1; // Segue para preencher a próxima posição
            resposta [p] += 1;
            k -= 1;
        }
        return resposta;
    }
};

