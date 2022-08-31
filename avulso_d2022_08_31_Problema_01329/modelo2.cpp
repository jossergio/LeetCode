class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> pegarDiagonal (vector<vector<int>>& matriz, int i, int j) {
        
        priority_queue<int, vector<int>, greater<int>> diagonal;
        
        while (i < matriz.size () && j < matriz [0].size ()) {
            diagonal.push (matriz [i][j]);
            i++;
            j++;
        }
        
        return diagonal;
    }
    
    void definirDiagonal (vector<vector<int>>& matriz, int i, int j, priority_queue<int, vector<int>, greater<int>>& diagonal) {
        
        while (i < matriz.size () && j < matriz [0].size ()) {
            matriz [i][j] = diagonal.top (); // A diagonal é ordenada inversamente
            diagonal.pop ();
            i++;
            j++;
        }
    }
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        priority_queue<int, vector<int>, greater <int>> tmp; // Será utilizado várias vezes
        
        for (int i = 0; i < mat.size (); i++) {
            tmp = pegarDiagonal (mat, i, 0);
            definirDiagonal (mat, i, 0, tmp);
        }
        
        for (int j = 1; j < mat [0].size (); j++) {
            tmp = pegarDiagonal (mat, 0, j);
            definirDiagonal (mat, 0, j, tmp);
        }
        
        return mat;
    }
};

