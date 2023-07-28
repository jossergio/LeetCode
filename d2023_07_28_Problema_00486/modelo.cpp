class Solution {
private:
    int diferenca (vector<int>& nums, int i, int j) {
        if (i == j) // Condição de saída
            return nums [i];
        // else
        return max (nums [i] - diferenca (nums, i + 1, j), nums [j] - diferenca (nums, i, j - 1));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return diferenca (nums, 0, nums.size () - 1) >= 0;
    }
};

