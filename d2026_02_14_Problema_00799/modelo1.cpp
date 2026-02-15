class Solution {
private:
    double transbordo (double d) {
        // Fiz por achaqufae facilitaria e evitaria pegadinhas do LeetCode
        if (d <= 1)
            return 0;
        // else
        return d - 1;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0)
            return 0; // Não há o que fazer
        vector<double> linha; // queue não permite acesso direto a itens
        linha.push_back (poured); // Joga tudo aqui
        for (int i = 1; i <= query_row; i += 1) { // A primeira linha já foi
            vector<double> tmp;
            tmp.push_back (transbordo (linha [0]) / 2);
            for (int j = 1; j < linha.size (); j += 1)
                tmp.push_back (( transbordo (linha [j - 1]) / 2) + ( transbordo (linha [j]) / 2));
            tmp.push_back (transbordo (linha [linha.size () - 1]) / 2);
            linha.swap (tmp);
        }
        if (query_glass < linha.size ())
            return (linha [query_glass] <= 1) ? linha [query_glass] : 1; // Pode ser um copo pelo meio da pirâmide
        // else - Não atinge a linha desejada
        return 0;
    }
};
