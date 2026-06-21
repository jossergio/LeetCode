class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        size_t t = costs.size ();
        sort (costs.begin (), costs.end ());
        int resp = 0;
        for (size_t i = 0; i < t; i += 1) {
            if (costs [i] <= coins) {
                coins -= costs [i];
                resp += 1;
            } else {
                break; // Não há solução a partir daqui
            }
        }
        return resp;
    }
};
