using Tipo1 = map<string, int>;
using Tipo2 = pair<string, int>;

class Solution {
private:
    Tipo2 getElemento (int& p, string f) {
        string e;
        e.push_back (f [p]); // É o maiusculo
        p += 1;
        while (p < f.size () && f [p] >= 'a' && f [p] <= 'z') { // Insere as minúsculas, se houver
            e.push_back (f [p++]);
        }
        string q;
        while (p < f.size () && f [p] >= '0' && f [p] <= '9') { // Gera a parte numérica, se houver
            q.push_back (f [p++]);
        }
        return Tipo2 {e, (q.size () == 0 ? 1 : atoi (q.c_str ()))};
    }
    
    Tipo1 montar (int& p, string f) {
        Tipo1 resposta;
        while (p < f.size ()) {
            if (f [p] == '(') {
                p += 1;
                for (auto [e, q]: montar (p, f)) {
                    resposta [e] += q;
                }
            } else {
                if (f [p] == ')') { // Pode ser, por ser de nível acima
                    p += 1;
                    string tmp;
                    while (p < f.size () && f [p] >= '0' && f [p] <= '9') {
                        tmp.push_back (f [p++]);
                    }
                    if (tmp.size () > 0) {
                        int v = atoi (tmp.c_str ());
                        for (auto& [a, b]: resposta) { // Sem ideia de nomes
                            b *= v;
                        }
                    }
                    break; // Sai desse nível
                } else { // Para esse caso, só pode ser uma letra maiuscula
                    Tipo2 tmp = getElemento (p, f);
                    resposta [tmp.first] += tmp.second;
                }
            }
        }
        return resposta;
    }
public:
    string countOfAtoms(string formula) {
        string resposta;
        int p = 0;
        for (auto [e, q]: montar (p, formula)) {
            resposta += e + (q == 1 ? "" : to_string (q));
        }
        return resposta;
    }
};

