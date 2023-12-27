class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int t = colors.size (); // Tanto faz, são do mesmo tamanho
        int i = 0;
        priority_queue<int, vector<int>, greater<int>> fila;
        int tmpCor; // Será utilizado o laço
        int resposta = 0;
        while (i < t) {
            tmpCor = colors [i];
            while (i < t && colors [i] == tmpCor) {
                fila.push (neededTime [i]);
                i += 1;
            }
            // Sai com, pelo menos, um
            while (fila.size () != 1) {
                resposta += fila.top ();
                fila.pop ();
            }
            fila.pop (); // Retira o último (ou único)
            // O contador já foi incrementado no laço interno
        }
        return resposta;
    }
};

