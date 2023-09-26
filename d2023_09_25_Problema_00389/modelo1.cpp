class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> letras;
        for (char c: t)
            letras [c] += 1;
        for (char c: s)
            letras [c] -= 1;
        for (auto [c, v]: letras)
            if (v == 1)
                return c;
        // else
        return 0; // Só para ter algo aqui, pois não deve chegar
    }
};

