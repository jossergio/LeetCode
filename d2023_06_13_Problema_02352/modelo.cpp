class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int contagem = 0;
        int t = grid.size (); // Dimensões iguais, quadrado
        for (int i = 0; i < t; i += 1)
            for (int j = 0; j < t; j += 1) {
                bool iguais = true; // Pressupõe
                for (int k = 0; k < t; k += 1)
                    if (grid [i][k] != grid [k][j]) {
                        iguais = false;
                        break; // k
                    }
                if (iguais)
                    contagem += 1;
            }
        return contagem;
    }
};

