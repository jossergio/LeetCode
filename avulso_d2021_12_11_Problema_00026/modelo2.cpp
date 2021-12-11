class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, n = nums.size ();
        if (n == 0) // Vai que...
            return 0;
        for (int i = 1; i < n; i++) {
            if (nums [k] != nums [i]) {
                nums [++k] = nums [i];
            }
        } // for i
        return k + 1;
    }
};

