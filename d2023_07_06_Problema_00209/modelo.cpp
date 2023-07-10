class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int t = nums.size ();
        int resposta {0};
        int soma = nums [0];
        int i = {0}, j {0};
        while (i < t && j < t && resposta != 1) { // Sai, se atinge o valor mínimo
            if (soma >= target) {
                if (resposta == 0)
                    resposta = j - i + 1; // Primeiro valor a considerar; para evitar usar maxint e checar no final
                else
                    resposta = min (resposta, j - i + 1);
                soma -= nums [i]; // Tira esse possível maior
                i += 1;
                if (j < i) {
                    j = i; // i nunca pode ultrapassar j
                    soma = nums [i]; // Só um elemento
                }
            } else { // if soma >= target
                j += 1;
                if (j < t)
                    soma += nums [j]; // Acrescenta
            }
        }
        return resposta;
    }
};

