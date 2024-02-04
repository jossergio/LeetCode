class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort (nums.begin (), nums.end ());
        vector<vector<int>> resposta;
        for (int& n: nums) {
            if (resposta.empty () || resposta.back ().size () == 3) {
                resposta.push_back (vector<int> {n});
            } else {
                for (int& v: resposta.back ())
                    if (n - v > k)
                        return vector<vector<int>> {};
                // Se passou, pode adicionar
                resposta.back ().push_back (n);
            }
        }
        return resposta;
    }
};

