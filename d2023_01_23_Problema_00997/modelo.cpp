class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> confiancas (n + 1, 0); // Despresará a posição 0
        for (auto t: trust) {
            confiancas [t [1]] += 1;
            confiancas [t [0]] -= 1; // Tira um possível valor cruzado
        }
        for (int i = 1; i <= n; i += 1)
            if (confiancas [i] == n - 1) // O próprio juiz não confia em si; tira do total
                return i;
        return -1;
    }
};

