class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 1; // Nunca é o primeiro; nem o último
        while (i < arr.size () - 1 && arr [i] < arr [i + 1])
            i += 1;
        return i;
    }
};

