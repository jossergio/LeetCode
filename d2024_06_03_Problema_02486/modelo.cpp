class Solution {
public:
    int appendCharacters(string s, string t) {
        const size_t ts = s.size ();
        const size_t tt = t.size ();
        size_t s_i = 0;
        size_t t_i = 0;
        while (s_i < ts && t_i < tt) {
            if (s [s_i] == t [t_i])
                t_i += 1;
            s_i += 1; // Sempre é incrementado
            }
        return tt - t_i;
    }
};

