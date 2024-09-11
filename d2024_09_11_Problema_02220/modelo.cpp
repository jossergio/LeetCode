class Solution {
public:
    int minBitFlips(int start, int goal) {
        int contar = 0;
        while (start != 0 || goal != 0) {
            if ((start & 1) != (goal & 1)) {
                contar += 1;
            }
            start >>= 1;
            goal >>= 1;
        }
        return contar;
    }
};

