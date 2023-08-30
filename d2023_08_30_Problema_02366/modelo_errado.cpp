class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        stack<int> pilha;
        long long divisoes = 0; // Será a resposta
        pilha.push (nums [nums.size () - 1]); // Será de trás para frente
        for (int i = nums.size () - 2; i >= 0; i -= 1) {
            int anterior = pilha.top ();
            int atual = nums [i];
            while (atual > anterior) {
                if (2 * anterior < atual) {
                    pilha.push (anterior); // Igualdade
                    divisoes += 1;
                    atual -= anterior;
                } else {
                    int resto = atual % 2;
                    atual /= 2;
                    pilha.push (atual + resto);
                    divisoes += 1;
                }
            }
            pilha.push (atual); // O que sobrou
        }
        return divisoes;
    }
};

