class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        int j = arr.size () - 1;
        while (i < j) {
            int meio = (i + j) / 2;
            if (arr [meio + 1] > arr [meio])
                i = meio + 1;
            else
                j = meio;
        }
        return i; // Ou j
    }
};

