class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maior, segundo;
        if (nums [1] > nums [0]) {
            maior = nums [1];
            segundo = nums [0];
        } else {
            maior = nums [0];
            segundo = nums [1];
        }
        for (int n: vector (nums.begin () + 2, nums.end ()))
            if (n > maior) {
                segundo = maior;
                maior = n;
            } else {
                if (n > segundo)
                    segundo = n;
            }
        return (maior - 1) * (segundo - 1);
    }
};

