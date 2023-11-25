class Solution {
private:
    int acumulados (vector<int>& nums, int i, int acumulado, vector<int>& resposta) {
        const int t = nums.size ();
        if (i < t) {
            acumulado += nums [i];
            int tmp = acumulados (nums, i + 1, acumulado, resposta);
            resposta [i] = ((i + 1) * (nums [i])) - acumulado;
            resposta [i] += tmp - ((t - i - 1) * (nums [i]));
            return nums [i] + tmp;
        }
        // else
        return 0;
    }
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> resposta (nums.size ());
        int tmp = acumulados (nums, 0, 0, resposta);
        return resposta;
    }
};

