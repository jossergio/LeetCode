class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size () - 1; // 0-begin
        int meio; // Para não fixar alocando dentro do laço
        while (i <= j) {
            meio = (i + j) / 2;
            if (nums [meio] == target)
                return meio;
            // else
            if (target > nums [meio])
                i = meio + 1;
            else
                j = meio - 1;
        }
        return i; // Por omissão, essa será a posição
    }
};

