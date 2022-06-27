bool ordem (int a, int b) {
    return a < b;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort (nums.begin (), nums.end (), ordem); // reverse não trabalhava direito no LeetCode
        return nums [nums.size () - k];
    }
};

