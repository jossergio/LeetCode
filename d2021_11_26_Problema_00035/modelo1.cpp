class Solution {
private:
    int encontrar (int inicio, int fim, int objetivo, vector<int> nums) {
        if (inicio >= fim) {
            if (nums [inicio] >= objetivo)
                return inicio;
            return inicio + 1;
        }
        int meio = (inicio + fim) / 2;
        if (nums [inicio] == objetivo) 
            return inicio;
        if (nums [fim] == objetivo)
            return fim;
        if (nums [meio] == objetivo)
            return meio;
        if (nums [meio] > objetivo)
            return (encontrar (inicio, meio - 1, objetivo, nums));
        return (encontrar (meio + 1, fim, objetivo, nums));
    } // encontrar

public:
    int searchInsert(vector<int>& nums, int target) {
        return (encontrar (0, nums.size () - 1, target, nums));
    }
};

