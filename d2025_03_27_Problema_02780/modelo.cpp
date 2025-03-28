class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> frente;
        unordered_map<int, int> fim;
        const size_t t = nums.size ();
        vector<pair<int, int>> acums = vector (t, pair<int, int> ());
        for (int i = 0; i < t; i += 1) {
            acums [i].first = ++frente [nums [i]];
            acums [t - i - 1].second = ++fim [nums [t - i - 1]];
        }
        for (int i = 0; i < t; i += 1) {
            if (acums [i].first * 2 > i + 1 && acums [i].second * 2 - 1 > t - i) return i;
        }
        return -1;
    }
};
