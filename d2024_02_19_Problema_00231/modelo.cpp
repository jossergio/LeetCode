class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) ? ((n - 1) & n) == 0 : false;
    }
};

