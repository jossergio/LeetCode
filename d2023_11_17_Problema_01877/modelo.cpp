class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort (nums.begin (), nums.end ());
        int i = 0;
        int j = nums.size () - 1;
        int maior = nums [i++] + nums [j--];
        while (i < j)
            maior = max (maior, nums [i++] + nums [j--]);
        return maior;
    }
};

