class Solution {
private:
    vector<int> temp;
    
    int i, f; // Controle inicial e final do vetor geral
    
    int soma = 0;
    int somaAlex = 0;
    int somaLee = 0;
    
    int modelo = 0;

// As próximas funções poderiam ser uma. Mas, quiz evitar passagens por referência com variáveis globais
    void somarAlex (int valor, int op) { // op: +1 adiciona, -1 subtrai
        somaAlex += op * valor;
        soma -= op * valor; // É o inverso
    }
    
    void somarLee (int valor, int op) { // idem somarAlex
        somaLee += op * valor;
        soma -= op * valor;
    }
    
    bool ganha (int alex, int lee) {
        if (f > i) {
            if (alex == 1)
                somarAlex (temp [i++], 1);
            else // é 1
                somarAlex (temp [f--], 1);
            if (lee == 1)
                somarLee (temp [i++], 1);
            else
                somarLee (temp [f--], 1);
            switch (modelo) {
                case 1:
                    if ((somaAlex > (soma + somaLee)) || 
                            ganha (1, -1) ||
                            ganha (-1, 1) ||
                            ganha (1, 1) ||
                            ganha (-1, -1))
                        return true;
                    break;
                case 2:
                    if ((somaAlex > (soma + somaLee)) || 
                            ganha (-1, 1) ||
                            ganha (1, 1) ||
                            ganha (1, -1) ||
                            ganha (1, -1))
                        return true;
                    break;
                    
                default:
                    if ((somaAlex > (soma + somaLee)) || 
                            ganha (1, 1) ||
                            ganha (1, -1) ||
                            ganha (-1, 1) ||
                            ganha (-1, -1))
                        return true;
            } // switch modelo
            if (lee == 1)
                somarLee (temp [--i], -1);
            else
                somarLee (temp [++f], -1);
            if (alex == 1)
                somarAlex (temp [--i], -1);
            else
                somarAlex (temp [++f], -1);
        }
        return false; // De uma forma ou de outra, Alex NÃO ganha
    } // ganha

public:
    bool stoneGame(vector<int>& piles) {
        for (int a = 0; a < piles.size (); a++)
            soma += piles [a];
        temp = piles;
        if (piles.size () > 2) {
            i = 0;
            f = temp.size () - 1;
            if (temp [1] > temp [f]) {
                modelo = 2;
                return (ganha (-1, 1) || ganha (1, 1) || ganha (-1, -1) || ganha (1, -1));
            }
            if (temp [0] > temp [f]) {
                modelo = 1;
                return (ganha (1, -1) || ganha (-1, 1) || ganha (1, 1) || ganha (-1, -1));
            } else { // if temp 0 > temp f
                modelo = 2;
                return (ganha (1, 1) || ganha (1, -1) || ganha (-1, 1) || ganha (-1, -1));
            } // if temp 0 > temp f ... else ...
        } // if piles.size > 2
        return true; // De uma forma ou de outra, ganha Alex
    } // stoneGame
}; // Class Solution

