class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mapa;
        int i = 0;
        const int t = nums.size ();
        int maior = 0;
        for (int j = 0; j < t; j += 1) {
            mapa [nums [j]] += 1;
            while (mapa [nums [j]] > k)
                mapa [nums [i++]] -= 1;
            maior = max (maior, j - i + 1);
        }
        return maior;
    }
};

