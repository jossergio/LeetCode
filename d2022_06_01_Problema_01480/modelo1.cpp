class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> resposta (nums.size ());
        
        resposta [0] = nums [0];
        
        for (int i = 1; i < nums.size (); i++)
            resposta [i] = resposta [i - 1] + nums [i];
        
        return resposta;
    }
};

