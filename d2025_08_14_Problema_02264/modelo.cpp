class Solution {
public:
    string largestGoodInteger(string num) {
        const int t = num.size ();
        int i = 0;
        char resposta = 0;
        while (i < t) {
            char tmp = num [i];
            int cont = 0;
            while (i < t && num [i] == tmp) {
                cont += 1;
                i += 1;
            }
            if (cont >= 3 && tmp > resposta)
                resposta = tmp;
        }
        string respostaEfetiva;
        if (resposta != 0)
            respostaEfetiva = string (3, resposta);
        return respostaEfetiva;
    }
};
