class Solution {
public:
    string sortVowels(string s) {

        function<bool(char)> ehVogal = [&] (char c) -> bool {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                return true;
            // else
            return false;
        };

        priority_queue<char, vector<char>, greater<char>> listaVogais;
        for (char c: s)
            if (ehVogal (c))
                listaVogais.push (c);
        for (int i = 0; i < s.size (); i += 1)
            if (ehVogal (s [i]) > 0) {
                s [i] = listaVogais.top ();
                listaVogais.pop ();
            }
        return s;
    }
};

