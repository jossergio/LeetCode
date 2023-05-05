class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vogais {'a', 'e', 'i', 'o', 'u'};
        function<bool (char)> ehVogal = [&vogais] (char c) -> bool {
            return vogais.count (c) > 0;
        };
        int contagem = 0;
        for (int i = 0; i < k && i < s.size (); i += 1)
            if (ehVogal (s [i]))
                contagem += 1;
        int maximo = contagem;
        for (int i = k; i < s.size () && maximo != k; i += 1) {
            if (ehVogal (s [i - k]))
                contagem -= 1;
            if (ehVogal (s [i]))
                contagem += 1;
            maximo = max (maximo, contagem);
        }
        return maximo;
    }
};

