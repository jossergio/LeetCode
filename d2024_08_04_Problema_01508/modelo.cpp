class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int modulo = 1000000007;
        vector<int> acumulados ((n * (n + 1)) / 2);
        int k = 0;
        const int t = nums.size ();
        for (int i = 0; i < t; i += 1) {
            acumulados [k++] = nums [i];
            for (int j = i + 1; j < t; j += 1) {
                acumulados [k] = acumulados [k - 1] + nums [j];
                k += 1;
            }
        }
        sort (acumulados.begin (), acumulados.end ());
        int resposta = 0;
        for (int i = left - 1; i < right; i += 1) {
            resposta = (resposta + acumulados [i]) % modulo;
        }
        return resposta;
    }
};

