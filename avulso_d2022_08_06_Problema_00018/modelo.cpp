class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if (nums.size () < 4) // Ou é isso ou converter cada size, que é uint, para int em cada local que aparecere aaixo
            return vector<vector<int>> ();
        
        set<vector<int>> resp;
        
        sort (nums.begin (), nums.end ());
        
        for (int a = 0; a < (nums.size () - 3); a++)
            for (int b = a + 1; b < nums.size () - 2; b++) {
                
                int inicio = b + 1, fim = nums.size () - 1;

                while (inicio < fim) {
                    
                    long int acumulado = long (nums [a]) + long (nums [b]) + long (nums [inicio]) + long (nums [fim]); // Tive que colocar, pois produziu estouro em alguns testes; coisas do LeetCode
                    
                    if (acumulado == target) {
                        resp.insert ({nums [a], nums [b], nums [inicio], nums [fim]});
                        inicio++;
                        fim--;
                    } else {
                        if (acumulado < target)
                            inicio++;
                        else
                            fim--;
                    } // else if acumulado == target
                } // while
            } // for b
        
        return vector<vector<int>> (resp.begin (), resp.end ());
    }
};

