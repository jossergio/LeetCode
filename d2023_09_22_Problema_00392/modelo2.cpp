class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int ts = s.size ();
        if (ts == 0) // Equivale a todas; adianta
            return true;
        int si = 0; // Acompanhará s
        for (char c: t) {
            if (c == s [si])
                si += 1;
            if (si == ts) // Nâo precisa mais procurar, achou todos de s em t
                return true;
        }
        return false; // Se chegou até aqui é porque não encontrou todos os correspondentes
    }
};

