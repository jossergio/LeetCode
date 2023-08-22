class Solution {
public:
    string convertToTitle(int columnNumber) {
        string resposta;
        while (columnNumber > 0) {
            resposta = string (1, char (((columnNumber - 1) % 26) + 65)) + resposta;
            columnNumber = (columnNumber - 1) / 26;
        }
        return resposta;
    }
};

