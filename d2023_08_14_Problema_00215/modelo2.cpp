class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort (nums.begin (), nums.end (), [&] (int a, int b) -> bool { return a < b; }); // reverse não trabalhava direito no LeetCode
        return nums [nums.size () - k];
    }
};

