class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int tt = t.size ();
        int i = 0; // Acompanhará t
        for (char c: s) {
            while (i < tt && c != t [i])
                i += 1;
            if (i >= tt) // Bastaria ser igual
                return false;
            i += 1; // Já vai para o próximo
        }
        return true; // Passou por tudo e sempre encontrou correspondente
    }
};

