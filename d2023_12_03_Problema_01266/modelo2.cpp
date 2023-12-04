class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int resposta = 0;
        const int t = points.size ();
        for (int i = 1; i < t; i += 1)
            resposta += max (abs (points [i][0] - points [i - 1][0]), abs (points [i][1] - points [i - 1][1]));
        return resposta;
    }
};

