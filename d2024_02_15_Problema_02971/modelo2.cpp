class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        const int t = nums.size ();
        sort (nums.begin (), nums.end ());
        long long soma = nums [0]; // O primeiro não tem o que somar
        long long resposta = -1; // Resposta padrão do problema
        for (int i = 1; i < t; i += 1) {
            if (soma > nums [i]) { // Naturalmente são desconsiderados polígonos de dois lados
                resposta = soma + nums [i];
            }
            soma += nums [i];
        }
        cout << soma;
        return resposta;
    }
};

