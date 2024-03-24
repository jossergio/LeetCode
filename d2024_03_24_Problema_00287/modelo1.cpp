class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> existe (nums.size () + 1, false); // nums tem valores 1-begin
        for (int n: nums)
            if (existe [n])
                return n;
            else
                existe [n] = true;
        return 0; // Para ter algo aqui
    }
};

