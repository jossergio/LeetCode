const int modulo = 1000000007;

class Solution {
private:
    int pegarSofas (const string& corredor, int& i) {
        int contar = 0;
        const int t = corredor.size ();
        while (i < t) {
            if (corredor [i] == 'S') {
                contar += 1;
                if (contar == 2)
                    break;
            } // else
            i += 1;
        }
        return contar; // Aqui, i aponta para um sofá ou para fora do corredor
    }
    int contarPlantas (const string& corredor, int &i) {
        int contar = 0;
        const int t = corredor.size ();
        while (i < t && corredor [i] == 'P') {
            contar += 1;
            i += 1;
        }
        return contar; // contar tem quantas plantas passaram
    }
public:
    int numberOfWays(string corridor) {
        const int t = corridor.size ();
        long long resposta = 0; // Inicialmente, até virar o elemento neutro da multiplicação
        int i = 0;
        while (i < t) {
            int tmp = pegarSofas (corridor, i);
            if (tmp == 1)
                return 0; // Sumariamente, a quantidade de sofás é ímpar e não formará duplas
            // else
            if (tmp == 0)
                break; // Não há mais o que fazer
            i += 1; // Sai do sofá
            tmp = contarPlantas (corridor, i) + 1; // +1, pois conta-se entre as plantas
            if (resposta == 0)
                resposta = 1; // Inicia a contagem aqui; elemento neutro da multiplicação
            if (i < t) { // Pois, se passou ao final, não irá contar esse trecho
                resposta = (resposta * tmp) % modulo;
            }
        }
        return resposta;
    }
};
