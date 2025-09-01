class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto adicionar = [] (int p, size_t t) -> double {
            return (double) (p + 1) / (t + 1) - (double) p / t;
        };
        priority_queue<pair<double, int>> fila;
        const size_t t = classes.size ();
        for (size_t i = 0; i < t; i += 1) {
            fila.push ({adicionar (classes [i][0], classes [i][1]), i});
        }
        while (extraStudents > 0) {
            auto [_, i] = fila.top ();
            fila.pop ();
            classes [i][0] += 1;
            classes [i][1] += 1;
            fila.push ({adicionar (classes [i][0], classes [i][1]), i});
            extraStudents -= 1;
        }
        double total = 0;
        while (!fila.empty ()) {
            auto [_, i] = fila.top ();
            fila.pop ();
            total += (double) classes [i][0] / classes [i][1];
        }
        return total / t;
    }
};
