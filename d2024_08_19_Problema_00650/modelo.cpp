class Solution {
public:
    int minSteps(int n) {
        int resposta = 0;
        int divisor = n / 2;
        while (divisor >= 1) {
            if (n % divisor == 0) {
                resposta += n / divisor;
                n = divisor;
                divisor /= 2;
            } else {
                divisor -= 1;
            }
        }
        return resposta;
    }
};

