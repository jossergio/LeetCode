/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* montar (vector<int>& nums, int esq, int dir) {
        
        TreeNode* resposta = nullptr;
        
        if (esq <= dir) {
            
            int base = (dir + esq) / 2;
            resposta = new TreeNode {nums [base], montar (nums, esq, base - 1), montar (nums, base + 1, dir)};
            
        }
        
        return resposta;
    } // montar
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return montar (nums, 0, nums.size () - 1);
    }
};

