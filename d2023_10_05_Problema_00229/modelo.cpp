class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mapa;
        int t = nums.size () / 3;
        set<int> existe;
        for (int v: nums) {
            mapa [v] += 1;
            if (mapa [v] > t)
                existe.insert (v);
        }
        return vector<int> (existe.begin (), existe.end ());
    }
};

