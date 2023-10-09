class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size () - 1;
        while (i <= j) {
            int meio = (i + j) / 2;
            if (nums [meio] == target) {
                i = meio;
                j = meio;
                while (i >= 0 && nums [i] == target)
                    i--;
                while (j < nums.size () && nums [j] == target)
                    j++;
                return vector<int> {i + 1, j - 1};
            }
            // else
            if (nums [meio] < target)
                i = meio + 1;
            else // Só pode ser maior
                j = meio - 1;
        }
        return vector<int> {-1, -1}; // Por omissão
    }
};

