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
    bool verificar (TreeNode *esquerda, TreeNode *direita) {
        if (esquerda == nullptr && direita == nullptr)
            return true;
        
        if (esquerda == nullptr && direita != nullptr)
            return false;
        
        if (direita == nullptr && esquerda != nullptr)
            return false;
        
        if (esquerda->val != direita->val)
            return false;
        
        return ((verificar (esquerda->left, direita->right)) && (verificar (esquerda->right, direita->left)));
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return verificar (root->left, root->right);
    }
};

