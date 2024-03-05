class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size () - 1;
        while (i < j) {
            if (s [i] != s [j]) // Não há mais o que fazer
                break;
            char c = s [i]; // Tanto faz
            while (i <= j && s [i] == c)
                i += 1;
            while (j >= i && s [j] == c)
                j -= 1;
        }
        return i <= j ? j - i + 1 : 0;
    }
};

