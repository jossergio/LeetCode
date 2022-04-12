class Solution {
private:
    int tM, tN;
    
    int contar (vector<vector<int>> &board, int m, int n) {
        int retorno = 0;
        for (int i = m - 1; i <= m + 1; i++)
            if (i >= 0 && i < tM)
                for (int j = n - 1; j <= n + 1; j++)
                    if (j >= 0 && j < tN)
                        if (!(i == m && j == n) && board [i][j] == 1)
                            retorno++;
        return retorno;
    }
    
    void processar (vector<vector<int>> &board, int i, int j) {
        int tmp = contar (board, i, j);
        i++;
        if (i < tM)
            processar (board, i, j);
        else {
            i = 0;
            j++;
            if (j < tN)
                processar (board, i, j);
            j--;
            i = tM;
        }
        i--;
        if ((tmp < 2 || tmp > 3) && board [i][j] == 1)
            board [i][j] = 0;
        if (tmp == 3 && board [i][j] == 0)
            board [i][j] = 1;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        tM = board.size ();
        tN = board [0].size ();
        processar (board, 0, 0);
    }
};

