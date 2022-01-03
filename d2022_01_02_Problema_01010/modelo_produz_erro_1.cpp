class Solution {
private:
    int fatorial (int n) {
        int resposta = 1; // Elemento neutro da multiplicação
        while (n > 1)
            resposta *= n--;
        return resposta;
    } // fatorial
    int arranjo2_div2 (int n) {
        // Retorna arranjo (matemática) de n dois a dois e dividido por dois
        // = ((n!) / (n - 2)!) / 2
        // A ordem importa. Por isso, dividir por dois
        if (n > 1)
            return (fatorial (n) / fatorial (n - 2)) / 2;
        return 0;
    } // arranjo2
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
        resposta += arranjo2_div2 (restos [0]); // Dois a dois; pela resposta, tem que ser em dupla
        resposta += arranjo2_div2 (restos [30]); // Idem; pela resposta, cada dupla forma 60seg
        return resposta;
    }
};

