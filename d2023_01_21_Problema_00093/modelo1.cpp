class Solution {
private:
    void montar (string s, int nivel, int indice, string atual, set<string>& respostas) {
        if (nivel == 4 || indice == s.size ()) { // 0-begin
            if (nivel == 4 && indice == s.size ())
                respostas.insert (atual);
            return; // Para evitar o else
        }
        if (s [indice] == '0')  { // Não pode ter outros após esse algarismo
            if (nivel != 0)
                atual += ".0";
            else
                atual += "0";
            montar (s, nivel + 1, indice + 1, atual, respostas);
        } else {
            string tmp;
            for (int i = indice; i < indice + 3 && i < s.size (); i += 1) {
                tmp += s [i];
                if (stoi (tmp) <= 255) {
                    if (nivel != 0)
                        montar (s, nivel + 1, i + 1, atual + "." + tmp, respostas);
                    else
                        montar (s, nivel + 1, i + 1, atual + tmp, respostas);
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        set<string> respostas;
        montar (s, 0, 0, "", respostas);
        return vector(respostas.begin (), respostas.end ());
    }
};

