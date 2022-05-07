class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int minimo = nums [0], maximo = nums [0];
        int i = 1;
        
        while (i < nums.size ()) {
            
            if (nums [i] < minimo)
                while (i < nums.size () && nums [i] < minimo) {
                    minimo = nums [i];
                    maximo = nums [i]; // Arrasta
                    i++;
                }
            else {
                maximo = nums [i];
                i++;
            }
            
            if (i < nums.size () && nums [i] > maximo)
                while (i < nums.size () && nums [i] > maximo) {
                    maximo = nums [i];
                    i++;
                }
            
            for (int j = i; j < nums.size (); j++)
                if (nums [j] > minimo && nums [j] < maximo)
                    return true;
            
        }
        
        return false;
    }
};

