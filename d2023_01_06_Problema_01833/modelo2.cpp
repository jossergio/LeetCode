class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort (costs.begin (), costs.end ());
        int contagem = 0;
        for (int c: costs) {
            if (coins >= c) {
                coins -= c;
                contagem += 1;
            } else
                break;
        }
        return contagem;
    }
};

