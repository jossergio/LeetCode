class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int indice {0};
        vector<int> indices = vector (2, 0);
        map<char, int> contadores;
        bool iguais = false;
        for (int i = 0; i < s.size (); i += 1) {
            iguais |= (++contadores [s [i]]) > 1;
            if (s [i] != goal [i]) {
                if (indice < 2)
                    indices [indice++] = i;
                else
                    return false;
            }
        }
        if (indice == 0)
            return iguais; // Há, ao menos, dois iguais que podem permutar
        if (indice == 2) {
            swap (s [indices [0]], s [indices [1]]);
        }
        return s == goal;
    }
};

