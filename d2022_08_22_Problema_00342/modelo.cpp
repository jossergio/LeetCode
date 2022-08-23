class Solution {
public:
    bool isPowerOfFour(int n) {
        
        long nLong = long (n);
        
        for (long int i = 1; i <= nLong; i *= 4)
            if (i == nLong)
                return true;
        
        return false;
    }
};

