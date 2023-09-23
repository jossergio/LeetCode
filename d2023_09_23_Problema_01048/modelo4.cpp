class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, list<string>> tamanhos;
        for (string w: words)
            tamanhos [w.size ()].push_back (w);
        unordered_map<string, int> corrente;
        
        function<int (string)> buscar = [&] (string w) -> int {
            if (corrente [w] == 0) {
                int t = w.size () + 1;
                for (string p: tamanhos [t]) {
                    int c1 = 0;
                    int c2 = 0;
                    int dif = 0;
                    while (dif < 2 && c1 < w.size () && c2 < p.size ()) {
                        if (w [c1] != p [c2])
                            dif += 1;
                        else
                            c1 += 1;
                        c2 += 1; // Belo pensamento, não?
                    }
                    if (dif <= 1) // Há uma, e somente uma, diferença, mesmo que a última
                        corrente [w] = max (corrente [w], buscar (p));
                }
                corrente [w] += 1; // Inclui o próprio
            }
            return corrente [w];
        }; // function buscar
        
        int resposta = 0;
        for (string w: words)
            resposta = max (resposta, buscar (w));
        return resposta;
    }
};

