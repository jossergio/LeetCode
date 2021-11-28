class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tamanho = nums.size ();
        vector<int> resposta (tamanho, 1); // Elemento neutro
        vector<int> acumulados (tamanho, 1); // Idem
        acumulados [0] = nums [0];
        for (int i = 1; i < tamanho; i++) {
            acumulados [i] = acumulados [i - 1] * nums [i];
        } // for i
        resposta [tamanho - 1] = acumulados [tamanho - 2];
        acumulados [tamanho - 1] = nums [tamanho - 1];
        for (int i = tamanho - 2; i > 0; i--) { // Observar o -2 e o >0
            resposta [i] = acumulados [i + 1] * acumulados [i - 1];
            acumulados [i] = acumulados [i + 1] * nums [i];
        }
        resposta [0] *= acumulados [1];
        return resposta;
    }
};

