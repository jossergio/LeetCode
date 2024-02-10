class Solution {
private:
    int buscar (string& s, int i, int j) {
        if (i >= 0 && j < s.size () && s [i] == s [j]) {
            return 1 + buscar (s, i - 1, j + 1);
        }
        // else
        return 0;
    }
public:
    int countSubstrings(string s) {
        int resposta = 0;
        for (int i = 0; i < s.size (); i += 1) {
            resposta += 1 + buscar (s, i - 1, i + 1) + buscar (s, i, i + 1);
            // O próprio, os ímpares e os pares
        }
        return resposta;
    }
};

