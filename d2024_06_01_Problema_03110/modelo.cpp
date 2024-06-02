class Solution {
public:
    int scoreOfString(string s) {
        const size_t t = s.size ();
        int soma = 0;
        for (size_t i = 1; i < t; i += 1)
            soma += abs (s [i] - s [i - 1]);
        return soma;
    }
};

