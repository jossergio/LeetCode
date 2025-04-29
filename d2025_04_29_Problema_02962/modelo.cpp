class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int t = nums.size ();
        long long resposta = 0;
        int i = 0, j = 0;
        int contagem = 0;
        int maior = *max_element (nums.begin (), nums.end ());
        while (j < t) {
            while (j < t && contagem < k) {
                if (nums [j] == maior)
                    contagem += 1;
                j += 1;
            }
            while (contagem >= k) {
                if (nums [i] == maior)
                    contagem -= 1;
                resposta += t - j + 1; // Basicamente, de i até o final
                i += 1;
            }
        }
        return resposta;
    }
};
