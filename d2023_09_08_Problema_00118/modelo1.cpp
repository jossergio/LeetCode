class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> linha (1, 1); // Será muito utilizada no laço, abaixo
        vector<vector<int>> resposta;
        resposta.push_back (linha); // Já joga a primeira linha
        vector<int> anterior (linha.begin (), linha.end ());
        for (int i = 1; i < numRows; i += 1) { // O while de numRows não informa a quantidade sequencial por linha
            linha.clear ();
            linha.push_back (1);
            for (int j = 1; j < i; j += 1)
                linha.push_back (anterior [j] + anterior [j - 1]);
            linha.push_back (1); // E termina assim
            resposta.push_back (vector (linha.begin (), linha.end ()));
            linha.swap (anterior);
        }
        return resposta;
    }
};

