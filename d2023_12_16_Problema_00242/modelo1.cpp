class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size () != t.size ())
            return false;
        vector<int> contador = vector (26, 0);
        const int tam = s.size (); // Tanto faz
        for (int i = 0; i < tam; i += 1) {
            contador [s [i] - 'a'] += 1;
            contador [t [i] - 'a'] -= 1;
        }
        for (int c: contador)
            if (c != 0) // Sobrou, para mais ou para menos
                return false;
        return true; // Passou nos testes
    }
};

