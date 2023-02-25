class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximo = 0;
        int menor = prices [0]; // Só para ter um valor definido
        for (int v: prices)
            if (v < menor)
                menor = v;
            else
                maximo = max (maximo, v - menor);
        return maximo;
    }
};

