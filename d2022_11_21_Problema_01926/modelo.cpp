struct Ponto {
    int y, x, nivel;
};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<Ponto> fila;
        fila.push ({entrance [0], entrance [1], 0});
        maze [entrance [0]][entrance [1]] = 'v'; // Visitado
        pair<int, int> direcoes [4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int limiteY = maze.size () - 1; // Será usado várias vezes
        int limiteX = maze [0].size () - 1;
        while (!fila.empty ()) {
            auto [y, x, nivel] = fila.front ();
            fila.pop ();
            nivel += 1; // Já soma para o próximo
            for (auto d: direcoes) {
                int ty = y + d.first;
                int tx = x + d.second;
                if (ty >= 0 && ty <= limiteY && tx >= 0 && tx <= limiteX) {
                    if (maze [ty][tx] == '.') {
                        
                        if (ty == 0 || ty == limiteY || tx == 0 || tx == limiteX)
                            return nivel; // Já tá incrementado
                        // else
                        fila.push ({ty, tx, nivel}); // Já estão incrementados
                        maze [ty][tx] = 'v'; // Visitado
                    }
                }
            }
        }
        return -1; // Não achou
    }
};

