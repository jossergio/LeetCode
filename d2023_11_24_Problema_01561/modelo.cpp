class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort (piles.begin (), piles.end (), greater<int> ());
        int resposta = 0;
        const int t = (piles.size () / 3) * 2;
        for (int i = 1; i < t; i += 2)
            resposta += piles [i];
        return resposta;
    }
};

