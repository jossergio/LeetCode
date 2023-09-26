class Solution {
private:
    double transbordo (double d) {
        // Facilitar a visão do código
      return d > 1 ? (d - 1) / 2 : 0;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0)
            return 0; // Não há o que fazer
        vector<double> linha; // queue não permite acesso direto a itens
        linha.push_back (poured); // Joga tudo aqui
        for (int i = 1; i <= query_row; i += 1) { // A primeira linha já foi
            vector<double> tmp (linha.size () + 1);
            tmp [0] = transbordo (linha [0]);
            for (int j = 1; j < linha.size (); j += 1)
                tmp [j] = transbordo (linha [j - 1]) + transbordo (linha [j]);
            tmp [linha.size ()] = transbordo (linha [linha.size () - 1]);
            linha = tmp; // Para o caso, melhor que swap
        }
        if (query_glass < linha.size ())
            return (linha [query_glass] <= 1) ? linha [query_glass] : 1; // Pode ser um copo pelo meio da pirâmide
        // else - Não atinge a linha desejada
        return 0;
    }
};

