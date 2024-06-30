class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> contArestas (n, 0);
        for (auto r: roads) {
            contArestas [r [0]] += 1;
            contArestas [r [1]] += 1;
        }
        long long valor = 1; // Primeiro valor da sequência
        long long acumulado = 0;
        sort (contArestas.begin (), contArestas.end ());
        // Usar o tipo long long para compatibilidade nas variáveis no cálculo
        for (long long a: contArestas)
            acumulado += a * valor++;
        return acumulado;
    }
};

