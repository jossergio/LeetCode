class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        const int tg = g.size ();
        const int ts = s.size ();
        sort (g.begin (), g.end ());
        sort (s.begin (), s.end ());
        int resposta = 0;
        int ig = 0, is = 0;
        while (ig < tg && is < ts) {
            while (is < ts && s [is] < g [ig])
                is += 1;
            if (is < ts) {
                resposta += 1;
                is += 1; // Tem que já seguir para o próxim
            }
            ig += 1;
        }
        return resposta;
    }
};

