class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;
        int tmp = n - 1;
        return (tmp & n) == 0;
    }
};

