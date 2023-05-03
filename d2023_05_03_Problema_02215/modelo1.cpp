class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> resposta (2, vector<int> ());
        sort (nums1.begin (), nums1.end ()); // Só para garantir
        sort (nums2.begin (), nums2.end ()); // Idem
        set<int> conjunto1 (nums1.begin (), nums1.end ()); // Tornam únicos os elementos
        set<int> conjunto2 (nums2.begin (), nums2.end ()); // Idem
        auto i = conjunto1.begin (); // O tipo é um iterator
        auto j = conjunto2.begin (); // Idem
        while (i != conjunto1.end () && j != conjunto2.end ()) {
            if (*i == *j) {
                i++;
                j++;
            } else {
                if (*i < *j) {
                    resposta [0].push_back (*i);
                    i++;
                } else { // *j > *i
                    resposta [1].push_back (*j);
                    j++;
                }
            }
        }
        while (i != conjunto1.end ()) {
            resposta [0].push_back (*i);
            i++;
        }
        while (j != conjunto2.end ()) {
            resposta [1].push_back (*j);
            j++;
        }
        return resposta;
    }
};

