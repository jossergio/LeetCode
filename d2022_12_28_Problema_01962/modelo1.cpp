class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int tamanho = piles.size ();
        make_heap (piles.begin (), piles.end ());
        int tmp; // Só para definir fora do laço
        while (k > 0) {
            tmp = piles.front ();
            pop_heap (piles.begin (), piles.end ());
            piles.pop_back ();
            tmp -= tmp / 2;
            piles.push_back (tmp);
            push_heap (piles.begin (), piles.end ());
            k -= 1;
        }
        return accumulate (piles.begin (), piles.end (), 0);
    }
};

