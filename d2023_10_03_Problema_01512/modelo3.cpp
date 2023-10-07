class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int resposta = 0;
        while (nums.size () > 0) {
            int cont = 0;
            int i = nums.size () - 1;
            int base = nums [i];
            while (i >= 0) {
                if (nums [i] == base) {
                    nums.erase (nums.begin () + i);
                    cont += 1;
                }
                i -= 1;
            }
            resposta += (cont * (cont - 1)) / 2; // Combinatória
        }
        return resposta;
    }
};

