class Solution {
private:
    void permutar (vector<vector<int>>& resp, vector<int>& nums, int pos) {
        if (pos == nums.size ()) {
            resp.emplace_back (nums);
        } else {
            for (int i = pos; i < nums.size (); i += 1) {
                swap (nums [i], nums [pos]); // Mesmo que seja o mesmo
                permutar (resp, nums, pos + 1);
                swap (nums [i], nums [pos]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> resp;
        permutar (resp, nums, 0);
        return resp;
    }
};

