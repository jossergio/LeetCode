class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap (piles.begin (), piles.end ());
        int acumulado = accumulate (piles.begin (), piles.end (), 0); // priority_queue não permite begin/end; tem que iniciar aqui e subtrair durante o laço
        int tmp; // Só para definir fora do laço
        while (k > 0) {
            tmp = heap.top ();
            heap.pop ();
            heap.push (tmp - tmp / 2);
            acumulado -= tmp / 2;
            k -= 1;
        }
        return acumulado;
    }
};

