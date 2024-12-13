class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long resposta = 0;
        map<int, priority_queue<int>> fila;
        const int t = nums.size ();
        for (int i = 0; i < t; i+= 1) fila [nums [i]].push (-i); // Entra como negativo, para facilitar a ordem
        vector<bool> marcados (t, false);
        for (auto [i, f]: fila) {
            while (!f.empty ()) {
                int k = -f.top (); // Reverte o sinal
                f.pop ();
                if (!marcados [k]) {
                    resposta += i;
                    marcados [k] = true;
                    if (k > 0) marcados [k - 1] = true;
                    if (k < t - 1) marcados [k + 1] = true;
                }
            }
        }
        return resposta;
    }
};

