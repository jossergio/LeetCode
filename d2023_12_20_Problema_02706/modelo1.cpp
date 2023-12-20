class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort (prices.begin (), prices.end ());
        const int t = prices.size ();
        for (int i = 0; i < t; i += 1)
            for (int j = i + 1; j < t; j += 1) {
                int v = money - prices [i] - prices [j];
                if (v >= 0)
                    return v; // Só
            }
        return money;
    }
};

