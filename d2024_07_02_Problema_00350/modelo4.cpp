class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> a;
        for (int v: nums1)
            a [v] += 1;
        vector<int> resposta;
        for (int i: nums2)
            if (a [i] > 0) {
                resposta.push_back (i);
                a [i] -= 1;
            }
        return resposta;
    }
};

