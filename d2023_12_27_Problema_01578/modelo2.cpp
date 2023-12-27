class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int t = colors.size (); // Tanto faz, são do mesmo tamanho
        int i = 0;
        int tmpCor, anterior; // Serão utilizados no laço
        int resposta = 0;
        while (i < t) {
            tmpCor = colors [i];
            anterior = neededTime [i];
            i += 1;
            while (i < t && colors [i] == tmpCor) {
                if (neededTime [i] < anterior) {
                    resposta += neededTime [i];
                } else {
                    resposta += anterior;
                    anterior = neededTime [i];
                }
                i += 1;
            }
            // O contador já foi incrementado
        }
        return resposta;
    }
};

