class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maximo = 0; // Inicial
        int atual = 0; // Idem
        for (int v: gain) {
            atual += v;
            maximo = max (maximo, atual);
        }
        return maximo;
    }
};

