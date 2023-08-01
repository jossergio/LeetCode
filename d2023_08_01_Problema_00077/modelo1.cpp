class Solution {
private:
    void combinar (vector<vector<int>>& v, vector<int> tmp, int i, int n, int k) {
        if (k > 0) {
            for (int j = i; j <= n; j += 1) {
                tmp.push_back (j);
                combinar (v, tmp, j + 1, n, k - 1);
                tmp.pop_back ();
            }
        } else
            v.emplace_back (tmp);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> resposta;
        combinar (resposta, vector<int> (), 1, n, k);
        return resposta;
    }
};

