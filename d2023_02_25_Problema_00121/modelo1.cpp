class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximo = 0;
        int maior = prices [0]; // Só para ter um valor definido
        int menor = prices [0]; // Idem
        for (int v: prices) {
            if (v < menor) {
                menor = v;
                maior = v; // Como se recomeçasse
            }
            if (v > maior) {
                maior = v;
                maximo = max (maximo, maior - menor);
            }
        }
        return maximo;
    }
};

