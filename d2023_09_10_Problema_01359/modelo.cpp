class Solution {
public:
    int countOrders(int n) {
        if (n == 1)
            return 1;
        // else
        return (n * (2l * n - 1) * countOrders (n - 1)) % 1000000007;
    }
};

