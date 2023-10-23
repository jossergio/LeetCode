class Solution {
public:
    bool isPowerOfFour(int n) {
        
        long nLong = long (n);
        
        for (long i = 1; i <= nLong; i <<= 2) // PotÊncia de 4 segue assim
            if (i == nLong) // Melhor que and bit a bit, aqui
                return true;
        
        return false;
    }
};

