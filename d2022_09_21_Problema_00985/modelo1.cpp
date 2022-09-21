class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> resposta;
        int acumulado = 0;
        
        for (int v: nums) {
            if (v % 2 == 0)
                acumulado += v;
        }
        
        for (int i = 0; i < queries.size (); i++) { // Preferi utilizar por índice
            if ((abs (nums [queries [i][1]]) % 2 == 0) && (abs (queries [i][0]) % 2 == 0)) { // Ambos pares
                acumulado += queries [i][0];
                nums [queries [i][1]] += queries [i][0];
            } else {
                if ((abs (nums [queries [i][1]]) % 2 == 1) && (abs (queries [i][0]) % 2 == 1)) { // Ambos ímpares
                    nums [queries [i][1]] += queries [i][0];
                    acumulado += nums [queries [i][1]];
                    cout << nums [queries [i][1]] << " " << acumulado << endl;
                } else { // Ambos diferentes, resultado é ímpar
                    if (abs (nums [queries [i][1]]) % 2 == 0) { // Tem que tirar esse
                        acumulado -= nums [queries [i][1]];
                        nums [queries [i][1]] += queries [i][0];
                    } else { // Quem é par é o de query; so crecenta em nums
                        nums [queries [i][1]] += queries [i][0];
                    }
                }
            }
            
            resposta.push_back (acumulado);
        }
        
        return resposta;
    }
};

