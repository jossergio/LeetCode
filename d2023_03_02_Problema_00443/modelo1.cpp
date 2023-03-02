class Solution {
private:
    void incluir (vector<char>& r, char a, int cont) {
        r.push_back (a);
        if (cont > 1) {
            string tmp = to_string (cont);
            for (char c: tmp)
                r.push_back (c);
        }
    }
public:
    int compress(vector<char>& chars) {
        char atual = chars [0]; // A definição do problema diz que haverá, pelo menos, um
        int contagemAtual = 1; // Sempre iniciará com esse valor, na contagem
        vector<char> resposta;
        for (int i = 1; i < chars.size (); i += 1)
            if (atual != chars [i]) {
                incluir (resposta, atual, contagemAtual);
                contagemAtual = 1; // Reinicia a contagem
                atual = chars [i]; // Atualiza o atual
            } else {
                contagemAtual += 1;
            }
        incluir (resposta, atual, contagemAtual); // Sempre haverá resquíscios
        chars.swap (resposta);
        return chars.size (); // Após atualizado
    }
};

