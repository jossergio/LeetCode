class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long divisoes = 0; // Será a resposta
        for (int i = nums.size () - 2; i >= 0; i -= 1) {
            if (nums [i] > nums [i + 1]) {
                long long cabe = ceil ((nums [i] + nums [i + 1] - 1) / nums [i + 1]); // Quantos cabem
                divisoes += (cabe - 1);
                nums [i] /= cabe;
            }
        }
        return divisoes;
    }
};

