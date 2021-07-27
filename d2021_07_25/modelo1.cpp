class Solution {
private:
    int maiorPotencia2Menor (int n) {
        int pot = -1;
        while (n >= pow (2, (1 + pot)))
            pot++;
        return pot;
    } // maiorPotencia2Menor

    bool temConsecutivo (int n) {
        int resto;
        bool ehUm = false;
        while (n > 0) {
            resto = n % 2;
            if (resto == 1)
                if (ehUm)
                    return true; // Vai logo
                else
                    ehUm = true; // Já prepara o próximo
            else
                ehUm = false;
            n /= 2;
        } // while n > 0
        return false;
    } // temConsecutivo

    int fibonacci (int n) { // Um Fibonacci recursivo
        // Pressuponho que eu só mande N
        switch (n) {
            case 0 : return 1;
            case 1 : return 2; // O modelo pedia assim
            default: return (fibonacci (n - 1) + fibonacci (n -2));
        }
        return 1; // Pare retornar algo
    } // fibonacci

    int fade (int n) {
    // Suaviza um incremento bem interessante para otimizar iterações
        if (n > 1)
            if (n == 2)
                return 1;
            else
                return ((2 * fade (n - 1)) + (1 - (n % 2)));
        return 0;
    }

public:
    int findIntegers(int n) {
        int limiar = maiorPotencia2Menor (n);
        int contarNaoTem = fibonacci (limiar); // Há uma lógica fantástica nesse algoritmo!
        int a = pow (2, limiar);
        int limite = pow (2, limiar) + fade (limiar);
        // Em seguida, conta até onde está
        while (a <= n && a <= limite)
            if (!temConsecutivo (a++)) // Já incrementa
                contarNaoTem++;
        return contarNaoTem;
    } // findIntegers
};

