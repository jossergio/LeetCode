class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> positivos;
        queue<int> negativos;
        vector<int> resposta (nums.size (), 0); // Já sabemos o tamanho de resposta
        for (int& n: nums) {
            if (n < 0)
                negativos.push (n);
            else // Só pode ser positivo
                positivos.push (n);
        }
        int ponteiro = 0; // Cada elemento preenchido no vetor de resposta
        while (!positivos.empty ()) { // Basta um; o problema tem igualdade na quantidade
            resposta [ponteiro++] = positivos.front ();
            resposta [ponteiro++] = negativos.front ();
            // A alternância é a acima
            positivos.pop ();
            negativos.pop ();
        }
        return resposta;
    }
};

