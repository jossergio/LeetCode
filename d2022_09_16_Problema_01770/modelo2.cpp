class Solution {
private:
    int buscar (vector<vector<pair<bool, int>>>& bl, vector<int>& nums, vector<int>& mults, int iter, int esq) {
        
        if (iter == mults.size ())
            return 0;
        //else
        
        if (bl [iter][esq].first)
            return bl [iter][esq].second;
        
        int e = nums [esq] * mults [iter] + buscar (bl, nums, mults, iter + 1, esq + 1);
        int d = nums [(nums.size () - 1) - (iter - esq)] * mults [iter] + buscar (bl, nums, mults, iter + 1, esq);
        
        bl [iter][esq].first = true;
        
        return bl [iter][esq].second = max (e, d);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        vector<vector<pair<bool, int>>> bloco (nums.size () + 1, vector (multipliers.size () + 1, pair (false, 0)));
        
        return buscar (bloco, nums, multipliers, 0, 0);
    }
};

