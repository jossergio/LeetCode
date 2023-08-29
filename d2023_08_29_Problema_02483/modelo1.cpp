class Solution {
public:
    int bestClosingTime(string customers) {
        int total = 0; // Iremos ajustar isso
        for (char c: customers)
            total += (c == 'Y'? 1: 0); // Vê que obterá o máximo acumulado ao final para a posição zero
        int atual = total;
        int resposta = 0; // Posição inicial
        int i = 1; // Posição atual, segunda casa
        for (char c: customers) {
            if (c == 'Y')
                total -= 1;
            else
                total += 1;
            if (total < atual) { // Igual, pois o menor tem preferência
                atual = total;
                resposta = i;
            }
            i += 1;
        }
        return resposta;
    }
};

