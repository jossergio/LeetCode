class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maior = 0; // Conterá a maior palavra
        string retorno = "";
        for (string s: strs)
            maior = max (maior, (int) s.size ());
        for (int posicao = 0; posicao < maior; posicao++) {
            char letra;
            if (posicao < strs [0].size ())
                letra = strs [0][posicao]; // A primeira palavra será a referência
            else
                return retorno; // Direto
            for (string s: strs) // Irá passar todas
                if (posicao < s.size ()) {
                    if (s [posicao] != letra)
                        return retorno;
                } else
                    return retorno;
            retorno += letra;
        }
        return retorno; // Só chega aqui se todos forem iguais
    }
};

