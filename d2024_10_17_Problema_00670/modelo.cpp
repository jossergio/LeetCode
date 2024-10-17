class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string (num);
        const size_t t = s.size ();
        unordered_map<char, size_t> maior; // Pega o maior off-set de algum algarismo
        unordered_map<char, size_t> menor; // Pega o menor...
        for (size_t i = 0; i < t; i += 1) { // Monta o mapa das posições
            maior [s [i]] = i;
            if (menor.count (s [i]) == 0) menor [s [i]] = i; // Só se ainda não há
        }
        for (char c1 = '9'; c1 >= '0'; c1 -= 1) {
            if (maior.count (c1) > 0) {
                int tmp = -1; // Pressupõe não ter localizado
                for (char c2 = c1 - 1; c2 >= '0'; c2 -= 1) {
                    if (menor.count (c2) > 0 && menor [c2] < maior [c1] && (tmp == -1 || tmp > menor [c2])) {
                        tmp = menor [c2];
                    }
                }
                if (tmp != -1) { // Achou com quem permutar
                    swap (s [tmp], s [maior [c1]]);
                    break;
                }
            }
        }
        return stoi (s);
    }
};

