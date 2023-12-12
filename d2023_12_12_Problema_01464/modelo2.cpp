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
        const int t = nums.size ();
        for (int i = 2; i < t; i += 1)
            if (nums [i] > maior) {
                segundo = maior;
                maior = nums [i];
            } else {
                if (nums [i] > segundo)
                    segundo = nums [i];
            }
        return (maior - 1) * (segundo - 1);
    }
};

