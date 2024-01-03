class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size () - 1; // Começarei de baixo
        int anterior; // Será definido abaixo
        // Busca o primeiro
        do { // Observar que n sempre virá >= 0; pelo menos, há uma linha
            anterior = count (bank [n].begin (), bank [n].end (), '1');
            n -= 1;
        } while (anterior == 0 && n >= 0);
        int resposta = 0;
        // Busca os demais
        while (n >= 0) {
            int contar; // Será definido abaixo
            do {
                contar = count (bank [n].begin (), bank [n].end (), '1');
                n -= 1;
            } while (contar == 0 && n >= 0);
            resposta += anterior * contar; // Mesmo que contar seja zero, o que só ocorre se não há mais linhas com valores
            anterior = contar;
        }
        return resposta;
    }
};

