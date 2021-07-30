class Solution {
private:
    int checar (vector<vector<int>>& mat, int posL, int posC, int tL, int tC) {
        if (mat [posL][posC] == 0)
            return 0; // Já retorna, pois, é o próprio e com distância zero
        int retorno = (tL > tC) ? tL : tC; // Assume o pior caso possível
        int k, tmp;
        for (k = 0; k < tL; k++)
            if (mat [k][posC] == 0) {
                if ((tmp = abs (posL - k)) < retorno) {
                    if (tmp == 1) {
                        return 1; // Agilidade. Depois do zero, é o menor possível
                    } else {
                        retorno = tmp;
                    }}}
        // Se encontrou valor "1", já retornou. Só executa se for necessário
        for (k = 0; k < tC; k++)
            if (mat [posL][k] == 0) {
                if ((tmp = abs (posC - k)) < retorno) {
                    if (tmp == 1) {
                        return 1; // Agilidade
                    } else {
                        retorno = tmp;
                    }}}
        return retorno;
    } // checar


public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int totalLinhas = mat.size ();
        int totalColunas = mat [0].size (); // Poderia ser qualquer linha
        int a, b;
        vector<vector<int>> retorno (mat); // Só para criar uma matriz de mesmo tamanho
        for (a = 0; a < totalLinhas; a++)
            for (b = 0; b < totalColunas; b++)
                retorno [a][b] = checar (mat, a, b, totalLinhas, totalColunas);
        return retorno;
    }
};

