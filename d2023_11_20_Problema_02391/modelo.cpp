class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metal = 0, papel = 0, vidro = 0;
        int passaMetal = 0, passaPapel = 0, passaVidro = 0; // Quando não tem mais no caminho, não precisa contar
        const int t = garbage.size ();
        for (int i = 0; i < t; i += 1) {
            if (i != 0) {
                int tmp = travel [i - 1];
                passaMetal += tmp;
                passaPapel += tmp;
                passaVidro += tmp;
                metal += tmp;
                papel += tmp;
                vidro += tmp;
            }
            for (char c: garbage [i]) {
                // Zera os pasaas, a cada necessidade
                switch (c) {
                    case 'M': metal += 1; passaMetal = 0; break;
                    case 'P': papel += 1; passaPapel = 0; break;
                    case 'G': vidro += 1; passaVidro = 0;
                        // Não precisa de default
                }
            }
        }
        return metal + papel + vidro - (passaMetal + passaPapel + passaVidro);
    }
};

