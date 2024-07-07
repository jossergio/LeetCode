class Solution {
public:
    int passThePillow(int n, int time) {
        int voltas = time / (n - 1);
        int resto = time % (n - 1);
        int resposta; // Definirei adiante
        if (voltas % 2 == 0) {
            resposta = resto + 1;
        } else {
            resposta = n - resto;
        }
        return resposta;
    }
};

