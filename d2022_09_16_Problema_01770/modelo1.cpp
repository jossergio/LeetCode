class Solution {
private:
    long buscar (vector<int>& n, vector<int>& m, int i, int j, int k, long long acum) {
        
        if (k == m.size ())
            return acum;
        
        return max (
            buscar (n, m, i + 1, j, k + 1, acum + (n [i] * m [k])),
            buscar (n, m, i, j - 1, k + 1, acum + (n [j] * m [k]))
        );
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return max (
            buscar (nums, multipliers, 1, nums.size () - 1, 1, nums [0] * multipliers [0]),
            buscar (nums, multipliers, 0, nums.size () - 2, 1, nums [nums.size () - 1] * multipliers [0])
        );
    }
};

