class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort (nums.begin (), nums.end ());
        int i = 0;
        const int t = nums.size ();
        const int fim = nums [t - 1];
        for (int v = 0; v <= fim; v += 1) {
            while (i < t && nums [i] < v) {
                i += 1;
            }
            if (v == t - i && nums [i] >= v) { // 0-begin x 1-begin
                return t - i;
            }
        }
        return -1;
    }
};

