class Solution {
private:
    int buscarLongo (int i, int j, const string& s, vector<vector<int>>& memo) {
        if (memo [i][j] != 0)
            return memo [i][j];
        if (i > j)
            return 0;
        // else
        if (i == j)
            return 1;
        if (s [i] == s [j])
            memo [i][j] = 2 + buscarLongo (i + 1, j - 1, s, memo);
        else
            memo [i][j] = max (buscarLongo (i + 1, j, s, memo), buscarLongo (i, j - 1, s, memo));
        return memo [i][j];
    }
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo (vector (s.size (), vector<int> (s.size (), 0)));
        return buscarLongo (0, s.size () - 1, s, memo);
    }
};

