class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int i = 0;
        int resposta = values [0]; // Só para ter uma referência
        for (int j = 1; j < values.size (); j += 1) {
            resposta = max (resposta, values [i] + values [j] + i - j);
            if (values [j] >= values [i] + i - j) i = j;
        }
        return resposta;
    }
};

