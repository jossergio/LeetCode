class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort (nums.begin (), nums.end ());
        
        int tamanho = nums.size ();
        int resp = 0;
        int le = 0, ld = nums.size () - 1;
        int diferenca; // Criar aqui para usar no laço abaixo
        
        while (le < ld) { // Isso garante que terá mais de dois
            
            diferenca = nums [le + 1] - nums [le];
            if (diferenca != 0) {
                for (int be = le; be >= 0; be--) {
                    nums [be] += diferenca;
                    resp += diferenca;
                }
            }// if
            le++;
            
            diferenca = nums [ld] - nums [ld - 1]; // Usar essa sequência, para ficar positivo sempre
            if (diferenca != 0) {
                for (int bd = ld; bd < tamanho; bd++) {
                    nums [bd] -= diferenca;
                    resp += diferenca; // Observar que sempre incrementa
                }
            } // if
            ld--;
        }
        
        return resp;
    }
};

