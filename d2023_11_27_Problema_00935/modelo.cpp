const int modulo = 1000000007;

class Solution {
private:
    vector<vector<int>> proximos {
        {4, 6}, // 0
        {6, 8}, // 1
        {7, 9}, // 2
        {4, 8}, // 3
        {3, 9, 0}, // 4
        {}, // 5; nenhum
        {1, 7, 0}, // 6
        {2, 6}, // 7
        {1, 3}, // 8
        {2, 4} // 9
    };
    int buscar (int n, int i, map<pair<int, int>, int>& mapa) {
        pair<int, int> indice = make_pair (n, i);
        if (mapa.count (indice) == 0) {
            if (n == 1) {
                mapa [indice] = 1;
            } else {
                mapa [indice] = 0;
                for (int j: proximos [i])
                    mapa [indice] = (mapa [indice] + buscar (n - 1, j, mapa)) % modulo;
            } // else n == 1
        }
        return mapa [indice];
    }
public:
    int knightDialer(int n) {
        map<pair<int, int>, int> mapa;
        int resposta = 0;
        for (int i = 0; i <= 9; i += 1)
            resposta = (resposta + buscar (n, i, mapa)) % modulo;
        return resposta;
    }
};

