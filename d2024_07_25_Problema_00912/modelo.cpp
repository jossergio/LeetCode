class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int> contagem;
        int maior = nums [0]; // Só por referência
        int menor = nums [0]; // Idem
        for (int n: nums) {
            contagem [n] += 1;
            if (n > maior)
                maior = n;
            if (n < menor)
                menor = n;
        }
        int k = 0; // Será índice para nums, no laço de atualização
        for (int i = menor; i <= maior; i += 1)
            if (contagem.count (i) > 0)
                while (contagem [i]-- > 0)
                    nums [k++] = i;
        return nums;
    }
};

