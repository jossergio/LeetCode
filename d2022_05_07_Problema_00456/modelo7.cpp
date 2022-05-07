class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int minimo = nums [0]; // Sempre haverá
        
        for (int j = 0; j < nums.size (); j++) {
            minimo = min (minimo, nums [j]);
            for (int k = j + 1; k < nums.size (); k++)
                if (nums [k] < nums [j] && minimo < nums [k])
                    return true;
        }
        
        return false;
    }
};

