const int precisao = 100; // Duas casas decimais para a precisão
class Solution {
private:
    static bool ordem (vector<int>& v1, vector<int>& v2) {
        if (v1 [0] == v2 [0]) // São iguais
            return v1 [1] < v2 [1]; // Pega a segunda coordenada
        // else
        return v1 [0] < v2 [0];
    }
    static int tang (vector<int> c1, vector<int> c2) {
        if (c1 [0] == c2 [0])
            return INT_MAX; // Seria infinito
        // else
        return ((c1 [1] - c2 [1]) / (c1 [0] - c2 [0]));
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort (coordinates.begin (), coordinates.end (), ordem);
        int tg = tang (coordinates [1], coordinates [0]);
        cout << tg << endl;
        for (int i = 2; i < coordinates.size (); i += 1) {
            if (tang (coordinates [i], coordinates [i - 1]) != tg)
                return false;
        }
        return true;
    }
};

