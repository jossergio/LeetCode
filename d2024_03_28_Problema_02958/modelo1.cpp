class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, queue<int>> memo;
        int base = 0;
        int maior = 0;
        const int t = nums.size ();
        for (int i = 0; i < t; i += 1) {
            int n = nums [i];
            memo [n].push (i);
            if (memo [n].size () > k) {
                int tmp = memo [n].front ();
                memo [n].pop ();
                if (base <= tmp)
                    base = tmp + 1;
            }
            maior = max (maior, i - base + 1);
        }
        return maior;
    }
};

