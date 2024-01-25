class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int t1 = text1.size ();
        const int t2 = text2.size ();
        vector<vector<int>> tabela (t1 + 1, vector<int> (t2 + 1, 0));
        int maximo = 0;
        for (int i = 0; i < t1; i += 1) {
            for (int j = 0; j < t2; j += 1) {
                if (text1 [i] == text2 [j]) {
                    int tmp = tabela [i][j] + 1; // Para facilitar visualizar
                    tabela [i + 1][j + 1] = tmp;
                    maximo = max (maximo, tmp);
                } else {
                    tabela [i + 1][j + 1] = max (tabela [i][j + 1], tabela [i + 1][j]);
                }
            }
        }
        return maximo;
    }
};

