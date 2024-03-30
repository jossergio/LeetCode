class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        auto f = [&nums] (int z) -> int {
            const int t = nums.size ();
            unordered_set<int> conjunto;
            unordered_map<int, int> mapa;
            int resposta = 0;
            int i = 0;
            for (int j = 0; j < t; j += 1) {
                mapa [nums [j]] += 1;
                conjunto.insert (nums [j]);
                while (conjunto.size () > z) {
                    mapa [nums [i]] -= 1;
                    if (mapa [nums [i]] == 0)
                        conjunto.erase (nums [i]);
                    i += 1;
                }
                resposta += j - i + 1;
            }
            return resposta;
        }; // f
        return f (k) - f (k - 1);
    }
};

