class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int tam = s.size ();
        int i = 0, j = 0;
        int acumulado = 0;
        int resposta = 0;
        vector<int> tmp (tam, 0); // Materá o valor de cada posição de comparação
        while (j < tam) {
            tmp [j] = abs (s [j] - t [j]);
            acumulado += tmp [j];
            if (acumulado <= maxCost) {
                resposta = max (resposta, j - i + 1);
            } else {
                while (i <= j && acumulado > maxCost) {
                    acumulado -= tmp [i];
                    i += 1;
                }
            }
            j += 1;
        }
        return resposta;
    }
};

