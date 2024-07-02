class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> a1;
        unordered_map<int, int> a2;
        for (int v: nums1)
            a1 [v] += 1;
        for (int v: nums2)
            a2 [v] += 1;
        vector<int> resposta;
        for (auto [i, v]: a1)
            for (int qtd = 0; qtd < min (v, a2 [i]); qtd += 1)
                resposta.push_back (i);
        return resposta;
    }
};

