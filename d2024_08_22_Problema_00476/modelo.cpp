class Solution {
public:
    int findComplement(int num) {
        int pot = 0, tmp = num;
        while ((tmp >>= 1) != 0)
            pot = (pot << 1) + 1;
        return (num xor pot) & pot;
    }
};

