class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // Observar que inicia da segunda linha e segunda coluna; 0-begin
        for (int i = 1; i < matrix.size (); i++)
            for (int j = 1; j < matrix [0].size (); j++)
                if (matrix [i][j] != matrix [i - 1][j - 1])
                    return false;
        return true; // Por omissão, se chegou até aqui
    }
};

