class Solution {
private:
    int buscar (int i, vector<int>& cost, vector<int>& memo) {
        if (i >= cost.size ())
            return 0; // Elemente neutro da adição
        // else
        if (memo [i] == -1)
            memo [i] = cost [i] + min (buscar (i + 1, cost, memo), buscar (i + 2, cost, memo));
        return memo [i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo (cost.size (), -1);
        return min (buscar (0, cost, memo), buscar (1, cost, memo));
    }
};

