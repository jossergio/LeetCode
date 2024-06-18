class Solution {
private:
    int pegarMaximo (int w, unordered_map<int, int>& m) {
        int r = 0;
        for (auto [d, p]: m) {
            if (d <= w) {
                r = max (r, p);
            }
        }
        return r;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        unordered_map<int, int> maximos;
        const int t = difficulty.size ();
        for (int i = 0; i < t; i += 1) {
            maximos [difficulty [i]] = max (maximos [difficulty [i]], profit [i]);
        }
        const int minimo = *min_element (difficulty.begin (), difficulty.end ()); // Não pesquisará trabalhadores que não possam atingir esse nível
        int resposta = 0;
        for (int w: worker) {
            if (w >= minimo)
                resposta += pegarMaximo (w, maximos);
        }
        return resposta;
    }
};

