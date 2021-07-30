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

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int totalLinhas = mat.size ();
        int totalColunas = mat [0].size (); // Poderia ser qualquer linha
        int a, b;
        vector<vector<int>> retorno (mat); // Só para criar uma matriz de mesmo tamanho
        for (a = 0; a < totalLinhas; a++)
            for (b = 0; b < totalColunas; b++)
                retorno [a][b] = checar (mat, a, b, totalLinhas, totalColunas);
        return retorno;
    } // updateMatrix

void mostrarMatriz (vector<vector<int>>& mat) {
    int tamanho = mat.size ();
    int tamanhoInterno = mat [0].size ();
    int a, b;
    for (a = 0; a < tamanho; a++) {
        for (b = 0; b < tamanhoInterno; b++)
            std::cout << " " << mat [a][b];
        std::cout << std::endl;
    } // for a
}
int main() {
//    vector<vector<int>> matriz = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
/*
    vector<vector<int>> matriz = {
        {1,0,1,1,0,0,1,0,0,1},
        {0,1,1,0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,0,1,0},
        {1,1,1,1,0,1,0,0,1,1}
    };
*/
/*
    vector<vector<int>> matriz = {
        {1, 1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 1, 1, 1, 1},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 0}
    };
*/
    vector<vector<int>> matriz = {
        {0,0,1,0,1,1,1,0,1,1},
        {1,1,1,1,0,1,1,1,1,1},
        {1,1,1,1,1,0,0,0,1,1},
        {1,0,1,0,1,1,1,0,1,1},
        {0,0,1,1,1,0,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,1},
        {1,1,1,1,0,1,0,1,0,1},
        {0,1,0,0,0,1,0,0,1,1},
        {1,1,1,0,1,1,0,1,0,1},
        {1,0,1,1,1,0,1,1,1,0}};

    vector<vector<int>> resultado = updateMatrix (matriz);
    std::cout << "Original:" << std::endl;
    mostrarMatriz (matriz);
    std::cout << "Resultado:" << std::endl;
    mostrarMatriz (resultado);
} // main

