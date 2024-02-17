class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        const int t = nums.size ();
        sort (nums.begin (), nums.end ());
        vector<long long> somas (t, 0);
        somas [0] = nums [0]; // O primeiro não tem o que somar
        long long resposta = -1; // Resposta padrão do problema
        for (int i = 1; i < t; i += 1) {
            somas [i] = somas [i - 1] + nums [i];
            if (somas [i - 1] > nums [i]) { // Naturalmente são desconsiderados polígonos de dois lados
                resposta = somas [i];
            }
        }
        return resposta;
    }
};

