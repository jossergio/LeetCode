class Solution {
private:
    void inserir (vector<vector<int>>& resposta, int i, vector<int>& nums, vector<int>& tmp) {
        if (i < nums.size ()) {
            for (int j = i; j < nums.size (); j += 1) {
                tmp.push_back (nums [j]);
                resposta.push_back (vector<int> (tmp.begin (), tmp.end ()));
                inserir (resposta, j + 1, nums, tmp);
                tmp.pop_back ();
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> resposta;
        vector<int> tmp;
        resposta.push_back (tmp); // O vazio também faz parte da resposta
        inserir (resposta, 0, nums, tmp);
        return resposta;
    }
};

