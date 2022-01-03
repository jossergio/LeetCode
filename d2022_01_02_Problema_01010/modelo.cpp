class Solution {
private:
    int incremento_incrementado (int n) {
        // Uma forma de calcular arranjo doi a  dois dividido por dois
        // Por fatorial, o LeetCode coloca situações para valores elevados, que não cabem em long
        int resposta = 0;
        if (n > 1) {
            int incremento = 1;
            for (int i = 2; i <= n; i++)
                resposta += incremento++;
        } // if n > 1
        return resposta;
    } // incremento_incrementado
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> restos (60, 0) ;
        for (vector<int>::iterator v = time.begin (); v != time.end (); v++)
            restos [*v % 60]++;
        int resposta = 0;
        for (int i = 1; i < 30; i++)
            resposta += (restos [i] * restos [60 - i]);
        // Resto 0 e 30 não possuem pares naturais;
        // 0 sozinho já é uma resposta; porém, pela definição do problema, tem que ser em par
        // 30 só forma com outro 30 e tem que procurar um par 30
        resposta += incremento_incrementado (restos [0]); // Dois a dois; pela resposta, tem que ser em dupla
        resposta += incremento_incrementado (restos [30]); // Idem; pela resposta, cada dupla forma 60seg
        return resposta;
    }
};

