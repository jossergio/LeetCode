class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> resposta (numRows, vector (1, 1)); // Já faz a primeira linha e os primeiros itens das demais
        for (int i = 1; i < numRows; i += 1) {
            for (int j = 1; j < i; j += 1)
                resposta [i].push_back (resposta [i - 1][j] + resposta [i - 1][j - 1]);
            resposta [i].push_back (1);
        }
        return resposta;
    }
};

