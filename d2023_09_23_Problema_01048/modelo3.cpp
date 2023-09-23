class Solution {
bool previo (string s1, string s2)  {
    // s1 é menor em um aunidade que s2
    int c1 = 0;
    int c2 = 0;
    int dif = 0;
    while (dif < 2 && c1 < s1.size () && c2 < s2.size ()) {
        if (s1 [c1] != s2 [c2])
            dif += 1;
        else
            c1 += 1;
        c2 += 1; // Belo pensamento, não?
        if (dif > 1) // Achou mais de uma diferença
            return false;
    }
    return true;
}

public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, list<string>> tamanhos;
        int tMaximo = 0;
        for (string w: words) {
            tamanhos [w.size ()].push_back (w);
            tMaximo = max (tMaximo, (int) w.size ());
        }
        
        unordered_map<string, int> maximos;
        int resposta = 0;
        for (int i = tMaximo; i > 0; i -= 1) {
            for (string s: tamanhos [i]) {
                for (string p: tamanhos [i + 1])
                    if (previo (s, p))
                        maximos [s] = max (maximos [s], 1 + maximos [p]); // Inclui o próprio
                maximos [s] = max (maximos [s], 1); // O LeetCode montou uma pegadinha, com um item repetido, e tive que jogar o próprio item atual no laço, senão teria redundância
                resposta = max (resposta, maximos [s]);
            }
        }
        return resposta;
    }
};

