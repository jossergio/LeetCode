class Solution {
int buscar (vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {
    if (i < grid.size () && j < grid [0].size ()) {
        if (grid [i][j] == 0) { // Não é obstáculo
            if (memo [i][j] == 0) {
                if (i == grid.size () - 1 && j == grid [0].size () - 1)
                    memo [i][j] = 1; // A última posição sempre tem um passo
                else
                    memo [i][j] = buscar (grid, i + 1, j, memo) + buscar (grid, i, j + 1, memo);
            }
            return memo [i][j];
        }
    }
    return 0; // Notar que esse é para quando estoura os limites do quadro; também é quando tem obstáculo na posição
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> memo (obstacleGrid.size (), vector (obstacleGrid [0].size (), 0));
        return buscar (obstacleGrid, 0, 0, memo);
    }
};

