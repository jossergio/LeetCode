class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int tamanho = questions.size ();
        vector<long long> memo (tamanho);
        for (int i = tamanho - 1; i >= 0; i -= 1) {
            memo [i] = questions [i][0];
            int salto = questions [i][1];
            if (i + salto + 1 < tamanho)
                memo [i] += memo [i + salto + 1];
            for (int j = 1; j + i < tamanho && j <= salto; j += 1) {
                if (memo [i] >= memo [i + j])
                    break;
                else
                    memo [i] = memo [i + j];
            }
        }
        return *max_element (memo.begin (), memo.end ());
    }
};
