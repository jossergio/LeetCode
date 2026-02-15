class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0)
            return 0; // Não há o que fazer
        vector<double> linha (1, poured); // queue não permite acesso direto a itens; joga tudo no 1o
        for (int i = 1; i <= query_row; i += 1) { // A primeira linha já foi
            vector<double> tmp (linha.size () + 1, 0);
            for (int j = 0; j < linha.size (); j += 1) {
                double transbordo = linha [j] > 1 ? (linha [j] - 1) / 2 : 0;
                tmp [j] += transbordo; // Observar a adição
                tmp [j + 1] = transbordo; // Já joga a outra metade para o próximo        
            }
            linha = tmp; // Para o caso, melhor que swap
        }
        if (query_glass < linha.size ())
            return min (linha [query_glass], 1.0); // Pode ser um copo pelo meio da pirâmide
        // else - Não atinge a linha desejada
        return 0;
    }
};
