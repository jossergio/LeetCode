class Solution {
public:
    int totalMoney(int n) {
        int segunda = 1; // Segunda-feira
        int proximo = 1;
        int resposta = 0;
        for (int i = 1; i <= n; i += 1) {
            resposta += proximo;
            proximo += 1;
            if (i % 7 == 0) {
                segunda += 1;
                proximo = segunda;
            }
        }
        return resposta;
    }
};

