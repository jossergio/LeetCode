class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int limiteX = grid.size () - 1;
        const int limiteY = grid [0].size () - 1;

        auto calcular = [&] (int x, int y) -> int {
            if (grid [x][y] == 0)
                return 0;
            // else
            int acumulado = 0;
            if (x == 0 || grid [x - 1][y] == 0)
                acumulado += 1;
            if (x == limiteX || grid [x + 1][y] == 0)
                acumulado += 1;
            if (y == 0 || grid [x][y - 1] == 0)
                acumulado += 1;
            if (y == limiteY || grid [x][y + 1] == 0)
                acumulado += 1;
            return acumulado;
        }; // calcular

        int resposta = 0;
        for (int i = 0; i <= limiteX; i += 1) // limites já são - 1
            for (int j = 0; j <= limiteY; j += 1)
                resposta += calcular (i, j);
        return resposta;
    }
};

