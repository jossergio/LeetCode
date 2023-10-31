class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        const int t = pref.size ();
        vector<int> r (t, 0);
        r [0] = pref [0];
        int acum = pref [0];
        for (int i = 1; i < t; i += 1) {
            r [i] = acum ^ pref [i];
            acum ^= r [i];
        }
        return r;
    }
};

