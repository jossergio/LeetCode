class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort (prices.begin (), prices.end ());
        int v = money - prices [0] - prices [1]; // Os dois valores menores
        return v >= 0 ? v : money;
    }
};

