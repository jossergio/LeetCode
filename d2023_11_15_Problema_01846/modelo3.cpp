class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort (arr.begin (), arr.end ());
        int ultimo = arr [0];
        if (ultimo != 1)
            ultimo = 1;
        const int t = arr.size ();
        int tmp; // Só para definir fora do laço
        for (int i = 1; i < t; i += 1) { // Já começa do segundo
            tmp = arr [i];
            ultimo = (tmp <= ultimo + 1 ? tmp : ultimo + 1);
        }
        return ultimo;
    }
};

