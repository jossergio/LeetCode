class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> resposta (queries.size ());
        int acumulado = 0;
        
        for (int v: nums) {
            if (v % 2 == 0)
                acumulado += v;
        }
        
        for (int i = 0; i < queries.size (); i++) { // Preferi utilizar por índice
            
            if (abs (nums [queries [i][1]]) % 2 == 0) // Retira e, se for o caso, adiciona na sentença seguinte
                acumulado -= nums [queries [i][1]];
            
            nums [queries [i][1]] += queries [i][0]; // Registra o novo falor
            
            if (abs (nums [queries [i][1]]) % 2 == 0) // Se o novo valor for par, acumula
                acumulado += nums [queries [i][1]];
            
            resposta [i] = acumulado;
        }
        
        return resposta;
    }
};

