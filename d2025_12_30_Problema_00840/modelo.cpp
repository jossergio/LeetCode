class Solution {
private:
    bool e_magico (vector<vector<int>>& v, int i, int j) {
        set<int> teste;
        for (int ii = 0; ii < 3; ii += 1)
            for (int jj = 0; jj < 3; jj += 1)
                if (teste.count (v [i + ii][j + jj]) > 0)
                    return false;
                else
                    teste.insert (v [i + ii][j + jj]);
        if (teste.size () != 9) return false;
        vector<int> teste2 (teste.begin (), teste.end ());
        sort (teste2.begin (), teste2.end ());
        if (teste2 [0] != 1 && teste2 [8] != 9) return false; // Só servem valores entre 1 e 9, inclusive
        if (teste2 [8] - teste2 [0] != 8) return false;
        int tmp = v [i][j] + v [i][j + 1] + v [i][j + 2]; // Base
        if (v [i + 1][j] + v [i + 1][j + 1] + v [i + 1][j + 2] != tmp) return false;
        if (v [i + 2][j] + v [i + 2][j + 1] + v [i + 2][j + 2] != tmp) return false;
        if (v [i][j] + v [i + 1][j] + v [i + 2][j] != tmp) return false;
        if (v [i][j + 1] + v [i + 1][j + 1] + v [i + 2][j + 1] != tmp) return false;
        if (v [i][j + 2] + v [i + 1][j + 2] + v [i + 2][j + 2] != tmp) return false;
        if (v [i][j] + v [i + 1][j + 1] + v [i + 2][j + 2] != tmp) return false;
        if (v [i][j + 2] + v [i + 1][j + 1] + v [i + 2][j] != tmp) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size () < 3 || grid [0].size () < 3) return 0;
        int contagem = 0;
        for (int i = 0; i < grid.size () - 2; i += 1)
            for (int j = 0; j < grid [0].size () - 2; j += 1)
                if (e_magico (grid, i, j))
                    contagem += 1;
        return contagem;
    }
};
