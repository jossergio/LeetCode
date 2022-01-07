class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1; // LeetCode
        int compara = 0, tmp = n;
        while ((tmp >>= 1) != 0)
            compara = (compara << 1) + 1;
        return (n ^ compara) & compara;
    }
};

