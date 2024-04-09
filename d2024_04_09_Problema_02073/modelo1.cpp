class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        const int t = tickets.size ();
        int contador = 0;
        int i = 0; // Início da fila
        while (tickets [k] > 0) {
            if (tickets [i] > 0) {
                tickets [i] -= 1;
                contador += 1;
            }
            i += 1;
            if (i == t)
                i = 0; // Volta para o início da fila
        }
        return contador;
    }
};

