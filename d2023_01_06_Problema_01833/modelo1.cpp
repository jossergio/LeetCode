class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort (costs.begin (), costs.end ());
        int i = 0; // Também barcara a resposta
        while (i < costs.size () && coins >= costs [i]) { // for não cai bem, aqui
            coins -= costs [i];
            i += 1;
        }
        return i;
    }
};

