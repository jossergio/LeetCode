class Solution {
private:
    static bool ordem (int a, int b) {
        if (a > b)
            return true;
        // else
        return false;
    }
public:
    int maxProduct(vector<int>& nums) {
        
        sort (nums.begin (), nums.end (), ordem);
        
        return (nums [0] - 1) * (nums [1] - 1);
    }
};

