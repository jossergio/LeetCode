class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mapa;
        for (int v: nums)
            if ((++mapa [v]) > 1)
                return true;
        return false; // Por omissão
    }
};

