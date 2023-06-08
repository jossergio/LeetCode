class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int contagem = 0;
        const int limite = grid [0].size () - 1;
        for (auto interno: grid) {
            int i = limite;
            while (i >= 0 && interno [i] < 0) {
                contagem += 1;
                i--;
            }
        }
        return contagem;
    }
};

