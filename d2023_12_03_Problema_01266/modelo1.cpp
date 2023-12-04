class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int antX = points [0][0];
        int antY = points [0][1];
        int atualX; // Será usado no laço
        int atualY; // Idem
        int tX, tY; // Idem
        const int t = points.size ();
        int resposta = 0;
        for (int i = 1; i < t; i += 1) {
            atualX = points [i][0];
            atualY = points [i][1];
            tX = abs (atualX - antX);
            tY = abs (atualY - antY);
            resposta +=((tX > tY) ? tX : tY);
            antX = atualX;
            antY = atualY;
        }
        return resposta;
    }
};

