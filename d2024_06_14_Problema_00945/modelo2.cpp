class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        const int t = nums.size ();
        const int maximo = *max_element (nums.begin (), nums.end ());
        vector<int> contagens (maximo + t + 1); // Será tipo um hashmap; deverá conter espaço para os possíveis excedentes
        for (int n: nums) {
            contagens [n] += 1;
        }
        int resposta = 0;
        for (int i = 0; i < contagens.size (); i += 1) {
            if (contagens [i] > 1) {
                int duplicados = contagens [i] - 1; // Irá jogar o excedente para os seguinte
                contagens [i + 1] += duplicados; // Há, sempre, um de sobra no vetor
                contagens [i] = 1; // Só para ajustar; não precisaria
                resposta += duplicados;
            }
        }
        return resposta;
    }
};

