class Solution {
private:
    vector<int> converter (char c) {
        // 96 é o anterior ao 'a', pois esse é convertido para 1
        c -= 96;
        vector<int> retorno;
        while (c > 0) {
            retorno.push_back (c % 10);
            c /= 10;
        }
        for (int v: retorno) cout << v << " ";
        return retorno;
    }
    vector<int> converter_i (int i) {
        vector<int> retorno;
        while (i > 0) {
            retorno.push_back (i % 10);
            i /= 10;
        }
        return retorno;
    }
    int soma (vector<int> v) {
        int resposta = 0;
        for (int i: v) {
            resposta += i;
        }
        return resposta;
    }
public:
    int getLucky(string s, int k) {
        int acumulado = 0;
        for (char c: s) {
            acumulado += soma (converter (c));
        }
        k -= 1; // Já fez o primeiro passo
        while (k > 0 && acumulado >= 10) { // Abaixo desse valor, ficará repetitivo
            int tmp = 0;
            for (int i: converter_i (acumulado)) {
                tmp += i;
            }
            acumulado = tmp;
            k -= 1;
        }
        return acumulado;
    }
};

