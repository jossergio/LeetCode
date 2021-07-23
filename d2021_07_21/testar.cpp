#include <string>
#include <iostream> // std::cout
#include "modelo1.h"

// #define DEBUG

    bool esquerda (std::string &s, int p, bool f) {
        // Tive que separar os if's para evitar índice negativo
#ifdef DEBUG
std::cout << "Entrando em esquerda" << std::endl;
std::cout << "\tString: " << s << std::endl;
std::cout << "\tPosição: " << p << std::endl;
std::cout << "\tFez direita: " << f << std::endl;
#endif
        if (p > 1)
            if (s [p - 1] == '.' && (s [p - 2] != 'R' || f)) {
                s [p - 1] = 'L';
                return true; // Para agilizar e etc
            } // if s p - 1... &&
        if (p == 1)
            if (s [p - 1] == '.') {
                s [p - 1] = 'L';
                return true;
            } // if s p - 1...
    return false;
    } // esquerda
    
    bool direita (std::string &s, int p, int t) {
        // Tive que separar os if's para evitar índice negativo
#ifdef DEBUG
std::cout << "Entrando em direita" << std::endl;
std::cout << "\tString: " << s << std::endl;
std::cout << "\tPosição: " << p << std::endl;
std::cout << "\tTamanho: " << t << std::endl;
#endif
        if (p < t - 2)
            if (s [p + 1] == '.' && s [p + 2] != 'L') {
                s [p + 1] = 'R';
                return true; // Para agilizar e etc
            } // if s p - 1... &&
        if (p == t - 2)
            if (s [p + 1] == '.') {
                s [p + 1] = 'R';
                return true;
            } // s p + 1...
    return false;
    } // direita

    string pushDominoes(std::string dominoes) {
        bool alterou = false;
        bool saltar = false;
        bool fezDireita = false;
        int tamanho = dominoes.length ();
        int posicao = 0; // Só para inicializar
        string retorno = dominoes;
        do {
            alterou = false;
            for (posicao = 0; posicao < tamanho; posicao++)
                if (!saltar)
                    switch (retorno [posicao]) {
                        case 'R' : alterou = (saltar = fezDireita = direita (retorno, posicao, tamanho)) || alterou; break;
                        case 'L' : alterou = (esquerda (retorno, posicao, fezDireita)) || alterou; fezDireita = false; // Não precisa de break, pois...
                        case '.' : saltar = false;
                    } // switch dominoes posicao
                else // if !fezDireita
                    saltar = false;
        } while (alterou);
    return retorno;
    } // pushDominoes

void testes (std::string s)                 {
    std::cout << "Fazendo   : " << s << std::endl;
    std::cout << "Resultado : " << pushDominoes (s) << std::endl << std::endl;
} // testes

int main (){
//    testes (".L.R...LR..L..");
//    testes ("R.R.L");
    testes ("L..L..RR......L.");
    testes ("...RL....R.L.L........RR......L....R.L.....R.L..RL....R....R......R.......................LR.R..L.R.");
} // main

