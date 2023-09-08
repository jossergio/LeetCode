class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> resposta; 
        vector<int> linha (1, 1); // Será utilizado no laço; declarar aqui evita tempo de redeclaração/alocação; já é a primeira linha
        resposta.push_back (vector (linha.begin (), linha.end ()));
        for (int i = 1; i < numRows; i += 1) {
            linha.clear ();
            linha.push_back (1);
            for (int j = 1; j < i; j += 1)
                linha.push_back (resposta [i - 1][j] + resposta [i - 1][j - 1]);
            linha.push_back (1);
            resposta.push_back (vector (linha.begin (), linha.end ()));
        }
        return resposta;
    }
};

