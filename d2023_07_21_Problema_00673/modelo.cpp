class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int t = nums.size ();
        vector<int> comprimentos (t, 0);
        vector<int> contagens (t, 0);
        
        function<void (int)> calcular = [&] (int i) {
            if (comprimentos [i] != 0)
                return;
            comprimentos [i] = 1;
            contagens [i] = 1;
            for (int j = 0; j < i; j += 1) {
                if (nums [j] < nums [i]) {
                    calcular (j);
                    if (comprimentos [j] + 1 > comprimentos [i]) {
                        comprimentos [i] = comprimentos [j] + 1;
                        contagens [i] = 0;
                    }
                    if (comprimentos [j] + 1 == comprimentos [i])
                        contagens [i] += contagens [j];
                }
            }
        };
        
        int maximo = 0;
        for (int i = 0; i < t; i += 1) {
            calcular (i);
            if (comprimentos [i] > maximo)
                maximo = comprimentos [i];
        }
        int resposta = 0;
        for (int i = 0; i < t; i += 1)
            if (comprimentos [i] == maximo)
                resposta += contagens [i];
        return resposta;
    }
};

