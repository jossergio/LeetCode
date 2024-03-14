class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        const int t = nums.size ();
        int contador = 0;
        for (int i = 0; i < t; i += 1) {
            int soma = 0;
            for (int j = i; j < t; j += 1) {
                soma += nums [j];
                if (soma == goal) {
                    contador += 1;
                } else {
                    if (soma > goal) // A partir daqui, não há mais como obter goal
                        break;
                }
            }
        }
        return contador;
    }
};

