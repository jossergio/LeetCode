class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        const int t = tickets.size ();
        int contador = 0;
        for (int i = 0; i < t; i += 1)
            if (i <= k)
                contador += min (tickets [i], tickets [k]);
            else
                contador += (tickets [i] < tickets [k]) ? tickets [i] : tickets [k] - 1;
        return contador;
    }
};

