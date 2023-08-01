class Solution {
private:
    void combinar (vector<vector<int>>& v, vector<int>& tmp, int i, int n, int pos, int k) {
        if (pos == k) // Lembrar que pos é 0-indexed e k não
            v.emplace_back (tmp);
        else {
            for (int j = i; j <= n; j += 1) {
                tmp [pos] = j;
                combinar (v, tmp, j + 1, n, pos + 1, k);
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> resposta;
        vector<int> tmp (k, 0);
        combinar (resposta, tmp, 1, n, 0, k);
        return resposta;
    }
};

