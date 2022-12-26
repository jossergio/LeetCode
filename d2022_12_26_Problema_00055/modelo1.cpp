class Solution {
private:
    bool auxiliar (vector<int>& nums, int posicao, vector<bool>& testados) {
        if (posicao + nums [posicao] >= nums.size () - 1) // Chega ao fim
            return true;
        // else
        testados [posicao] = true;
        for (int i = posicao + nums [posicao]; i > posicao; i--) {
            if ((!testados [i]) && (auxiliar (nums, i, testados)))
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

