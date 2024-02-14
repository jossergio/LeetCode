class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> resposta (nums.size (), 0); // Já sabemos o tamanho de resposta
        int positivos = 0, negativos = 1; // O primeiro positivo sempre fica no início
        for (int& n: nums) {
            if (n < 0) {
                resposta [negativos] = n;
                negativos += 2; // Já segue para a próxima posição em que ficará o próximo negativo
            }
            else  {// Só pode ser positivo
                resposta [positivos] = n;
                positivos += 2; // Idem
            }
        }
        return resposta;
    }
};

