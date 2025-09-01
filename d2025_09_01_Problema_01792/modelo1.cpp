class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto adicionar = [] (int p, int t) -> double {
            return (double) (p + 1) / (t + 1) - (double) p / t;
        };
        priority_queue<pair<double, pair<int, int>>> fila;
        for (auto& v: classes) {
            fila.push ({adicionar (v [0], v [1]), {v [0], v [1]}});
        }
        while (extraStudents > 0) {
            auto [p, t] = fila.top ();
            fila.pop ();
            fila.push ({adicionar (t.first + 1, t.second + 1), {t.first + 1, t.second + 1}});
            extraStudents -= 1;
        }
        double total = 0;
        while (!fila.empty ()) {
            auto [_, t] = fila.top ();
            fila.pop ();
            total += (double) t.first / t.second;
        }
        return total / classes.size ();
    }
};
