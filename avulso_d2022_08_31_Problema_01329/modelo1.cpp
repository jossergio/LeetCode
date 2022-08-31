class Solution {
private:
    static bool ordem (int a, int b) {
        return (b < a); // Ordem inversa
    }
    
    vector<int> pegarDiagonal (vector<vector<int>>& matriz, int i, int j) {
        
        vector<int> diagonal;
        
        while (i < matriz.size () && j < matriz [0].size ()) {
            diagonal.push_back (matriz [i][j]);
            i++;
            j++;
        }
        
        return diagonal;
    }
    
    void definirDiagonal (vector<vector<int>>& matriz, int i, int j, vector<int>& diagonal) {
        
        while (i < matriz.size () && j < matriz [0].size ()) {
            matriz [i][j] = diagonal.back (); // A diagonal é ordenada inversamente
            diagonal.pop_back ();
            i++;
            j++;
        }
    }
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        for (int i = 0; i < mat.size (); i++) {
            vector<int> tmp = pegarDiagonal (mat, i, 0);
            sort (tmp.begin (), tmp.end (), ordem); // Tem que ser em ordem decrescente, para a recomposição utilizar como pilha
            definirDiagonal (mat, i, 0, tmp);
        }
        
        for (int j = 1; j < mat [0].size (); j++) {
            vector<int> tmp = pegarDiagonal (mat, 0, j);
            sort (tmp.begin (), tmp.end (), ordem); // Idem
            definirDiagonal (mat, 0, j, tmp);
        }
        
        return mat;
    }
};

