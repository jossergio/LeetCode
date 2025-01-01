class Solution {
private:
    int contador = 0;
    void buscar (vector<int>& nums, int i, int target) {
        if (i == nums.size ()) {
            if (target == 0) contador += 1;
        } else {
            buscar (nums, i + 1, target - nums [i]);
            buscar (nums, i + 1, target + nums [i]);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        buscar (nums, 0, target);
        return contador;
    }
};

