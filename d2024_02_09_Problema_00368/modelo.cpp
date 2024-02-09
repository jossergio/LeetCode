class Solution {
private:
    vector<int> buscar (int i, vector<int>& nums, vector<vector<int>>& memo) {
        if (memo [i].size () == 0) {
            memo [i].push_back (nums [i]);
            for (int j = i + 1; j < nums.size (); j += 1) {
                if ((nums [j] % nums [i]) == 0) {
                    vector<int> tmp = buscar (j, nums, memo);
                    tmp.insert (tmp.begin (), nums [i]);
                    if (tmp.size () > memo [i].size ()) {
                        memo [i] = tmp;
                    }
                }
            }
        }
        return memo [i];
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> resposta;
        sort (nums.begin (), nums.end ());
        const int t = nums.size ();
        vector<vector<int>> memo (t, vector<int> ());
        for (int i = 0; i < t; i += 1) {
            vector<int> tmp = buscar (i, nums, memo);
            if (tmp.size () > resposta.size ())
                resposta = tmp;
        }
        return resposta;
    }
};

