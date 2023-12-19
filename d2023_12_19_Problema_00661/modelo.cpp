class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        function<int (int, int)> calcular = [&img] (int y, int x) -> int {
            const int bx = max (0, x - 1);
            const int tx = min ((int) img [0].size () - 1, x + 1);
            const int by = max (0, y - 1);
            const int ty = min ((int) img.size () - 1, y + 1);
            int resposta = 0;
            int contagem = 0;
            for (int i = by; i <= ty; i += 1)
                for (int j = bx; j <= tx; j += 1) {
                    resposta += img [i][j];
                    contagem += 1;
                }
            return resposta / contagem;
        }; // calcular
        const int ty = img.size ();
        const int tx = img [0]. size ();
        vector<vector<int>> resposta (ty, vector (tx, 0));
        for (int i = 0; i < ty; i += 1)
            for (int j = 0; j < tx; j += 1)
                resposta [i][j] = calcular (i, j);
        return resposta;
    }
};

