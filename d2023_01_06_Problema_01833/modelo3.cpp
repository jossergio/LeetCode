class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int> acumulados; // map já mantém ordenado
        for (int c: costs)
            acumulados [c] += 1;
        int resposta = 0;
        for (auto [v, contagem]: acumulados) {
            if (coins < v)
                break; // Não tem mais moedas para comprar a partir daqui
            int tmp = min (contagem, coins / v); // Pega o que tem ou o resto das moedas
            resposta += tmp;
            coins -= tmp * v;
        }
        return resposta;
    }
};

