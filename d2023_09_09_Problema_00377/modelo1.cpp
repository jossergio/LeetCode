class Solution {
private:
    int buscar (vector<int>& nums, int target, unordered_map<int, int>& memo) {
        if (memo.count (target) == 0) {
            int acumulado = 0;
            for (int v: nums) {
                if (target - v == 0) {
                    acumulado += 1;
                } else {
                    if (target - v > 0)
                        acumulado += buscar (nums, target - v, memo);
                    else
                        break; // Será, daqui, sempre menor que zero
                }
            }
            memo [target] = acumulado;
        }
        return memo [target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort (nums.begin (), nums.end ()); // Para o que pensei, tem que estar ordenado
        unordered_map<int, int> memo;
        return buscar (nums, target, memo);
    }
};

