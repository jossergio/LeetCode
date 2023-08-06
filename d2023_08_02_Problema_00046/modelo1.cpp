class Solution {
private:
    void permutar (vector<vector<int>>& resp, vector<int>& nums, int pos, vector<bool>& usados, vector<int>& atual) {
        if (pos == nums.size ()) {
            resp.emplace_back (atual);
        } else {
            for (int i = 0; i < nums.size (); i += 1) {
                if (! usados [i]) {
                    usados [i] = true;
                    atual [pos] = nums [i];
                    permutar (resp, nums, pos + 1, usados, atual);
                    usados [i] = false;
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> resp;
        vector<int> atual (nums.size (), 0);
        vector<bool> usados (nums.size (), false);
        permutar (resp, nums, 0, usados, atual);
        return resp;
    }
};

