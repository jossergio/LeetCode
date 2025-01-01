class Solution {
private:
    void buscar (vector<int>& nums, int i, int target, int& contador) {
        if (i == nums.size ()) {
            if (target == 0) contador += 1;
        } else {
            buscar (nums, i + 1, target - nums [i], contador);
            buscar (nums, i + 1, target + nums [i], contador);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int contador = 0;
        buscar (nums, 0, target, contador);
        return contador;
    }
};

