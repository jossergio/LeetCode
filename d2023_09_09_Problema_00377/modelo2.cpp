class Solution {
private:
    int buscar (vector<int>& nums, int target, unordered_map<int, int>& memo) {
        
        if (memo.count (target) != 0)
            return memo [target];
        // else
        int acumulado = 0;
        for (int v: nums) {
            if (target - v == 0) {
                acumulado += 1;
            } else {
                if (target - v > 0)
                    acumulado += buscar (nums, target - v, memo);
            }
        }
        return memo [target] = acumulado;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return buscar (nums, target, memo);
    }
};

