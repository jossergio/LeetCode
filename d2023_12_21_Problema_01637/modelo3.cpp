class Solution {
static bool ordem (vector<int>& a, vector<int>& b) {
    return a [0] < b [0];
}
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort (points.begin (), points.end (), ordem);
        int resposta = 0;
        const int t = points.size ();
        for (int i = 1; i < t; i += 1)
            resposta = max (resposta, points [i][0] - points [i - 1][0]);
        return resposta;
    }
};

