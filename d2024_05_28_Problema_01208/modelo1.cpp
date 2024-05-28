class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int tam = s.size ();
        int i = 0, j = 0;
        int acumulado = 0;
        int resposta = 0;
        while (j < tam) {
            acumulado += abs (s [j] - t [j]);
            if (acumulado <= maxCost) {
                resposta = max (resposta, j - i + 1);
            } else {
                while (i <= j && acumulado > maxCost) {
                    acumulado -= abs (s [i] - t [i]);
                    i += 1;
                }
            }
            j += 1;
        }
        return resposta;
    }
};

