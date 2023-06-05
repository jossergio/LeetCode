const int precisao = 10000; // Duas casas decimais para a precisão
class Solution {
private:
    static int tang (vector<int> c1, vector<int> c2) {
        if (c1 [0] == c2 [0])
            return INT_MAX; // Seria infinito
        // else
        return int (double (c1 [1] - c2 [1]) / double ((c1 [0] - c2 [0])) * precisao);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int tg = tang (coordinates [0], coordinates [1]);
        for (int i = 2; i < coordinates.size (); i += 1) {
            if (tang (coordinates [0], coordinates [i]) != tg)
                return false;
        }
        return true;
    }
};

