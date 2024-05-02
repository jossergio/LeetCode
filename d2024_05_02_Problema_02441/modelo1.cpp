class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort (nums.begin (), nums.end());
        int i = 0;
        int j = nums.size () - 1;
        while (i < j + 1) {
            if (nums [j] < 0 || nums [i] > 0)
                return -1; // Nem tem como tentar mais
            if (abs (nums [i]) == abs (nums [j]))
                return nums [j]; // É esse
            if (abs (nums [i]) > nums [j])
                i += 1; // Segue para o próximo negativo
            else // Só pode ser menor
                j -= 1; // Proximo menor positivo
        }
        return -1; // Passou por tudo e não encontrou
    }
};

