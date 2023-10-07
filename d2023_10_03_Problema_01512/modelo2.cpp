class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int resposta = 0;
        while (nums.size () > 0) {
            int base = nums [0];
            int cont = 0;
            const int t = nums.size ();
            vector<int> posicoes;
            for (int i = 0; i < t; i += 1) {
                if (nums [i] == base) {
                    posicoes.insert (posicoes.begin (), i);
                    cont += 1;
                }
            }
            resposta += (cont * (cont - 1)) / 2; // Combinatória
            for (int i: posicoes)
                nums.erase (nums.begin () + i);
        }
        return resposta;
    }
};

