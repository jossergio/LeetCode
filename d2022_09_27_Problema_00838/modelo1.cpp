class Solution {
private:
    bool esquerda (string &s, int p, bool f) {
        // Tive que separar os if's para evitar índice negativo
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

    bool direita (string &s, int p, int t) {
        // Tive que separar os if's para evitar índice negativo
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

public:
    string pushDominoes(string dominoes) {
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
                    saltar = saltar = false;
        } while (alterou);
    return retorno;
    } // pushDominoes
};

