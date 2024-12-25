class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>> fila;
        for (int i = 0; i < nums.size (); i += 1) fila.push ({-nums [i], -i}); // Atenção para o sinal, pois a ordem é do menor para o maior
        while (k > 0) {
            auto [v, j] = fila.top ();
            fila.pop ();
            v = -v; // Repõe o sinal
            j = -j; // Idem
            nums [j] = (v *= multiplier);
            fila.push ({-v, -j}); // O sinal
            k -= 1;
        }
        return nums;
    }
};

