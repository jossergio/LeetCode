class Solution {
private:
    bool auxiliar (vector<int>& nums, int posicao, vector<bool>& testados) {
        if (testados [posicao])
            return false; // Já testou; e não chega ao fim
        // else
        testados [posicao] = true;
        if (posicao + nums [posicao] >= nums.size () - 1) // Chega ao fim
            return true;
        // else
        for (int i = 1; i <= nums [posicao]; i++) {
            if (auxiliar (nums, posicao + i, testados))
                return true;
        }
        return false; // Por definição, não atingiu
    }
public:
    bool canJump(vector<int>& nums) {
        vector<bool> testados (nums.size (), false);
        return auxiliar (nums, 0, testados);
    }
};

