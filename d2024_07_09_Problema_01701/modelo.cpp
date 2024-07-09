class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int tempo = 0;
        double acumulado = 0;
        for (auto i: customers) {
            if (tempo <= i [0]) {
                acumulado += i [1];
                tempo = i [0] + i [1];
            } else {
                acumulado += tempo - i[0] + i [1];
                tempo += i [1];
            }
        }
        return acumulado / customers.size ();
    }
};

