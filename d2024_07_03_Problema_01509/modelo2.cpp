class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int t = nums.size ();
        if (t <= 3)
            return 0; // Sumariamente
        sort (nums.begin (), nums.end ());
        return min ({nums [t - 1] - nums [3], nums [t - 2] - nums [2], nums [t - 3] - nums [1], nums [t - 4] - nums [0]});
    }
};

