class Solution {
public:
    int search(vector<int>& nums, int target) {
        function<int (int, int)> auxiliar = [&nums, &target, &auxiliar] (int i, int j) -> int {
            if (i <= j) {
                int meio = (i + j) / 2;
                if (target == nums [meio])
                    return meio;
                // else
                if (nums [meio] >= nums [i]) {
                    if (target < nums [meio] && target >= nums [i])
                        return auxiliar (i, meio - 1);
                    else
                        return auxiliar (meio + 1, j);
                }
                // else
                if (target <= nums [j] && target > nums [meio])
                    return auxiliar (meio + 1, j);
                else
                    return auxiliar (i, meio - 1);
            }
            // else
            return -1; // Não encontrou
        }; // auxiliar
        return auxiliar (0, nums.size () - 1);
    }
};

