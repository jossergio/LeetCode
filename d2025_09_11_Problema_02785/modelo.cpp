class Solution {
public:
    string sortVowels(string s) {
        set<char> vogais {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> listaVogais;
        for (char c: s)
            if (vogais.count (c) > 0)
                listaVogais.push_back (c);
        sort (listaVogais.begin (), listaVogais.end ());
        auto proximaVogal = listaVogais.begin ();
        for (int i = 0; i < s.size (); i += 1)
            if (vogais.count (s [i]) > 0) {
                s [i] = *proximaVogal;
                proximaVogal++;
            }
        return s;
    }
};
