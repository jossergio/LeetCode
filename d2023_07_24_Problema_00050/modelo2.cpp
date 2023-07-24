class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1; // De forma imediata
        long long n2 = n; // Para poder utilizar nesse tipo; precisa, para evitar estouros quando o menor dos inteiros precisa se tornar positivo, abaixo, em alguns testes
        if (n2 < 0) {
            n2 = -1 * n2; // Torna positivo
            x = 1 / x; // Já transforma em fração
        }
        double resposta = 1; // Elemento neutro da multiplicação
        while (n2 > 0) {
            if (n2 % 2 == 1) { // Ímpar
                resposta *= x;
                n2 -= 1;
            }
            x *= x;
            n2 /= 2;
        }
        return resposta;
    }
};

