class NumMatrix {
private:
    vector<vector<int>> acumulador;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        acumulador.clear ();
        
        for (int i = 0; i <= matrix.size (); i++) { // Notar que acrescentará 1 às dimensões
            acumulador.push_back (vector<int> (matrix [0].size () + 1, 0)); // Sempre haverá uma coluna a mais no acumulador
            if (i != 0) { // A linha 0 de acumulador será sempre zerada
                for (int j = 1; j < acumulador [i].size (); j++)
                    acumulador [i][j] = matrix [i - 1][j - 1] + acumulador [i][j - 1] + acumulador [i - 1][j] - acumulador [i - 1][j - 1]; // Tem que tirar a "intersecção" das somas
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return acumulador [row2 + 1][col2 + 1] - acumulador [row1][col2 + 1] - acumulador [row2 + 1][col1] + acumulador [row1][col1]; // Tem que retornar a intersecção
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

