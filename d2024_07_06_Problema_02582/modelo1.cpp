class Solution {
public:
    int passThePillow(int n, int time) {
        int p = 1; // Posição do travesseiro
        while (time > 0) {
            if (p == 1) {
                p = time >= n - 1 ? n : time + 1;
                time -= n - 1; // Não conta o 1o
            }
            if (p == n) { // Já testa no mesmo laço
                p = time >= n - 1 ? 1 : n - time;
                time -= n - 1;
            }
        }
        return p;
    }
};

