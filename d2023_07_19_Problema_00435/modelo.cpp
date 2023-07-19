class Solution {
private:
    static bool comparar (vector<int>& a, vector<int>& b) {
        if (a [1] == b [1])
            return a [0] < b [0];
        return a [1] < b [1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort (intervals.begin (), intervals.end (), comparar);
        int resposta = 0;
        int k = INT_MIN;
        for (auto item: intervals) {
            if (item [0] >= k)
                k = item [1];
            else
                resposta += 1;
        }
        return resposta;
    }
};

