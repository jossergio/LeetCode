class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort (nums.begin (), nums.end ());
        const int t = nums.size ();
        return (nums [t - 1] * nums [t - 2]) - (nums [0] * nums [1]); // Sempre há, no mínimo, 4, pela definição
    }
};

