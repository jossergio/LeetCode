class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> conts (3, 0); // Irá mapear os valores
        for (int n: nums)
            conts [n] += 1;
        int i = 0;
        for (int k = 0; k < 3; k += 1)
            while (conts [k]-- > 0)
                nums [i++] = k;
    }
};

