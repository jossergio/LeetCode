/*
= = = = = =
Código totalmente feito no PlayGround do LeetCode
Cheio de testes etc.
= = = = = =
*/

/* 
= = = = = = Essas duas funções produziram demora (TimeOut) = = = = = =
// Mas só quando usadas sozinhas!
*/
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

    int findIntegersVerificacao(int n) {
// Foi o que produziou a demora. Utilizei para verificação nos testes
        int contar = 0;
        for (int a = 0; a <= n; a++)
            if (!temConsecutivo (a))
                contar++;
        return contar;
    }


/*
void testes (int n) {
    std::cout << "Testando: " << n << " = " << (temConsecutivo (n) ? "Sim" : "Não") << std::endl;;
} // testes
*/

    int maiorPotencia2Menor (int n) {
        int pot = -1;
        while (n >= pow (2, (1 + pot)))
            pot++;
        return pot;
    } // maiorPotencia2Menor

    int menorPotencia2Maior (int n) {
        int pot = 0;
        while (n >= pow (2, (pot)))
            pot++;
        return pot;
    } // maiorPotencia2Menor

    int fade (int n) {
    // Suaviza um incremento bem interessante para otimizar iterações
        if (n > 1)
            if (n == 2)
                return 1;
            else
                return ((2 * fade (n - 1)) + (1 - (n % 2)));
        return 0;
    }
/*
    int findIntegers(int n) {
      return menorPotencia2Maior (n) - 1; 
    } // findIntegers
*/

    int fibonacci (int n) { // Um Fibonacci recursivo
        // Pressuponho que eu só mande N
        switch (n) {
            case 0 : return 1;
            case 1 : return 2; // O modelo pedia assim
            default: return (fibonacci (n - 1) + fibonacci (n -2));
        }
        return 1; // Pare retornar algo
    } // fibonacci

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

std::string verBinario (int n) {
    std::string ver = "";
    while (n > 0) {
        if (n % 2 == 1)
            ver = "1" + ver;
        else
            ver = "0" + ver;
        n /= 2;
    } // while n > 0
    return ver;
} // verBinario

void testesVerBinario (int n) {
    std::cout << "Valor de " << n << " em binário: " << verBinario (n);
    std::cout << " | menorPotencia2Maior: " << menorPotencia2Maior (n);
    std::cout << " | maiorPotencia2Menor: " << maiorPotencia2Menor (n);
    std::cout  << std::endl;
} // testesVerBinario

/*
void testesMaiorPotencia2Menor (int n) {
    int potencia = maiorPotencia2Menor (n);
    std::cout << "Maior potência de 2 menor que " << n << " = " << potencia << std::endl;
    std::cout << "\t 2 ^ " << potencia << " = " << pow (2, potencia) << std::endl;
} // testesMaiorPotencia2Menor
*/

/*
void testesMenorPotencia2Maior (int n) {
    int potencia = menorPotencia2Maior (n);
    std::cout << "Maior potência de 2 menor que " << n << " = " << potencia << std::endl;
    std::cout << "\t 2 ^ " << potencia << " = " << pow (2, potencia) << std::endl;
} // testesMaiorPotencia2Menor
*/

void testes (int n) {
    int potenciaMenor = maiorPotencia2Menor (n);
    std::cout << "Analisando " << n << std::endl;
    std::cout << "Fibonacci de: " << potenciaMenor << ": "<< fibonacci (potenciaMenor) << std::endl;
    for (int a = 0; a <= n; a++) 
        std::cout << "\t" << verBinario (a) << std::endl;
    std::cout << "Para valor " << n << " o resultado é: " << findIntegers (n);
    std::cout << " (Verificação: " << findIntegersVerificacao (n) << ")" << std::endl << std::endl;
} // testes

void testes2 (int n) { // Não mostra o andamento
    int potenciaMenor = maiorPotencia2Menor (n);
    std::cout << "Analisando " << n << std::endl;
    std::cout << "Menor potência: " << potenciaMenor << std::endl;
    std::cout << "O valor da menor potência é: " << pow (2, potenciaMenor) << std::endl;
    std::cout << "Fibonacci de: " << potenciaMenor << ": "<< fibonacci (potenciaMenor) << std::endl;
    std::cout << "Fade de: " << potenciaMenor << ": " << fade (potenciaMenor) << std::endl;
    std::cout << "Analisando no máximo até: " << pow (2, potenciaMenor) + fade (potenciaMenor) << std:: endl;
    std::cout << "Para valor " << n << " o resultado é: " << findIntegers (n);
//    std::cout << " (Verificação: " << findIntegersVerificacao (n) << ")";
    std::cout << std::endl << std::endl;
} // testes

int main() {

//    testes (0);
//    testes (1);
//    testes (2);
//    testes (3);
//    testes (4);
//    testes (5);
//    testes (6);
//    testes (32);
//    testes (100);
    testes2 (999999999);
    testes2 (10000000);


/*
    for (int a = 0; a < 255; a++)
        testesVerBinario (a);
*/

/*
    testesVerBinario (100);
    testesVerBinario (200);
    testesVerBinario (254);
    testesVerBinario (255);
*/
    
/*
    testesMaiorPotencia2Menor (0);
    testesMaiorPotencia2Menor (1);
    testesMaiorPotencia2Menor (2);
    testesMaiorPotencia2Menor (3);
    testesMaiorPotencia2Menor (4);
    testesMaiorPotencia2Menor (10);
    testesMaiorPotencia2Menor (20);
    testesMaiorPotencia2Menor (100);
    testesMaiorPotencia2Menor (254);
    testesMaiorPotencia2Menor (255);
    testesMaiorPotencia2Menor (256);
    testesMaiorPotencia2Menor (500);
    testesMaiorPotencia2Menor (1000);
*/
/*
    for (int a = 1; a <= 10; a++)
        for (int b = (pow (2, a) - 1); b <= (pow (2, a) + 1); b++)
            testesMaiorPotencia2Menor (b);
*/
/*    for (int a = 1; a <= 10; a++)
        for (int b = (pow (2, a) - 1); b <= (pow (2, a) + 1); b++)
            testesMenorPotencia2Maior (b);
*/
} // main

