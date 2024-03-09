class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        const int t1 = nums1.size ();
        const int t2 = nums2.size ();
        while (i < t1 && j < t2) {
            if (nums1 [i] == nums2 [j])
                return nums1 [i]; // Tanto faz; são iguais
            // else
            if (nums1 [i] < nums2 [j])
                i += 1;
            else
                j += 1;
        }
        return -1; // Não há
    }
};

