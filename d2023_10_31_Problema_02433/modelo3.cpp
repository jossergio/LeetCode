class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        const int t = pref.size ();
        int ant = pref [0];
        for (int i = 1; i < t; i += 1) {
            int tmp = pref [i];
            pref [i] = ant ^ pref [i];
            ant = tmp;
        }
        return pref;
    }
};

