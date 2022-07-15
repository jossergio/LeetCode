class Solution {
private:
    int pegarArea (vector<vector<int>>& grade, int linha, int coluna) {
        if (linha >= 0 && linha < grade.size () && coluna >= 0 && coluna < grade [0].size () && grade [linha][coluna] == 1) {
            grade [linha][coluna] = 0;
            return 1 + pegarArea (grade, linha - 1, coluna) + pegarArea (grade, linha, coluna - 1) + pegarArea (grade, linha + 1, coluna) + pegarArea (grade, linha, coluna + 1);
        }
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int resposta = 0;
        
        for (int i = 0; i < grid.size (); i++)
            for (int j = 0; j < grid [0].size (); j++)
                resposta = max (resposta, pegarArea (grid, i, j));
        
        return resposta;
    }
};

