class Solution {
public:
    int bestClosingTime(string customers) {
        int atual = 0;
        int menor = 0; // Pressupõe
        int resposta = 0; // Posição inicial
        int i = 1; // Posição atual, segunda casa
        for (char c: customers) {
            if (c == 'Y')
                menor -= 1;
            else
                menor += 1;
            if (menor < atual) { // Igual, pois o menor tem preferência
                atual = menor;
                resposta = i;
            }
            i += 1;
        }
        return resposta;
    }
};

