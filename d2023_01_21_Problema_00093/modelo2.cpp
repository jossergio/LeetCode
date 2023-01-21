class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        set<string> respostas;
        function<void (int, int, string)> montar;
        montar = [s, &respostas, &montar] (int nivel, int indice, string atual) -> void {
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
                montar (nivel + 1, indice + 1, atual);
            } else {
                string tmp;
                for (int i = indice; i < indice + 3 && i < s.size (); i += 1) {
                    tmp += s [i];
                    if (stoi (tmp) <= 255) {
                        if (nivel != 0)
                            montar (nivel + 1, i + 1, atual + "." + tmp);
                        else
                            montar (nivel + 1, i + 1, atual + tmp);
                    }
                }
            }
        };
        montar (0, 0, "");
        return vector(respostas.begin (), respostas.end ());
    }
};

