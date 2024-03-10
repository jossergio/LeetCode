class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> c1 (nums1.begin (), nums1.end ());
        sort (nums2.begin (), nums2.end ());
        vector<int> resposta;
        resposta.reserve (nums1.size () > nums2.size () ? nums1.size () : nums2.size ());
        for (int v: c1)
            if (binary_search (nums2.begin (), nums2.end (), v))
                resposta.push_back (v);
        return resposta;
    }
};

