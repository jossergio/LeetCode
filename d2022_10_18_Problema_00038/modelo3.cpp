class Solution {
private:
    string transformar (string s) {
        string retorno = "";
        char anterior = s [0]; // Já pega o primeiro
        int contar = 1; // E inicia com esse primeiro
        for (int i = 1; i < s.size (); i++) { // Inicia com o segundo
            char atual = s [i];
            if (atual == anterior) {
                contar += 1;
            } else {
                retorno += (to_string (contar) + anterior);
                anterior = atual;
                contar = 1; // Reinicia
            }
        }
        return retorno + to_string (contar) + anterior;
    }
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        // else
        return transformar (countAndSay (n - 1));
    }
};

