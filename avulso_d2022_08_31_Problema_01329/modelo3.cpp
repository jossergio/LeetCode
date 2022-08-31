class Solution {
private:
    void ordenarDiagonal (vector<vector<int>>& matriz, int i, int j) {
        
        priority_queue<int, vector<int>, greater<int>> diagonal;
        int tmpI = i, tmpJ = j;
        
        while (tmpI < matriz.size () && tmpJ < matriz [0].size ()) {
            diagonal.push (matriz [tmpI][tmpJ]);
            tmpI++;
            tmpJ++;
        }
        
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
        
        for (int i = 0; i < mat.size (); i++)
            ordenarDiagonal (mat, i, 0);
        
        for (int j = 1; j < mat [0].size (); j++)
            ordenarDiagonal (mat, 0, j);
        
        return mat;
    }
};

