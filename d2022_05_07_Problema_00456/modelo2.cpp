class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int menor = nums [0];
        
        for (int j = 1; j < nums.size () - 1; j++) {
            if (menor < nums [j])
                for (int k = j + 1; k < nums.size (); k++)
                    if (menor < nums [k] && nums [k] < nums [j])
                        return true;
            menor = min (menor, nums [j]);
        }
        
        return false;
    }
};

