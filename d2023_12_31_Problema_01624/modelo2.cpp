class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> p; // Posições
        const int t = s.size ();
        int resposta = -1; // Padrão, caso não encontre resposta
        for (int i = 0; i < t; i += 1) {
            if (p.find (s [i]) == p.end ())
                p [s [i]] = i;
            else
                resposta = max (resposta, i - p [s [i]] - 1); // Os extremos não contam
        }
        return resposta;
    }
};

