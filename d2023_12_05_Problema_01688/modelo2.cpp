class Solution {
public:
    int numberOfMatches(int n) {
        int resposta = 0;
        while (n > 1) {
            if (n % 2 == 0)
                resposta += n / 2;
            else {
                resposta += (n - 1) / 2;
                n += 1; // Um vai de lambuja
            }
            n /= 2;
        }
        return resposta;
    }
};

