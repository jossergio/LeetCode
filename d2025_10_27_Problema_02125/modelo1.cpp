class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int anterior = 0, resposta = 0;
        for (string& s: bank) {
            int atual = count (s.begin (), s.end (), '1');
            if (atual != 0) {
                resposta += atual * anterior; // O primeiro será multiplicado por zero, de toda forma
                anterior = atual;
            }
        }
        return resposta;
    }
};
