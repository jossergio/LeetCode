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
    int contar = 0;
    
    void procurar (TreeNode *root, int maior) {
        
        // Nunca vem nullptr
        if (maior <= root->val)
            contar++;
        
        maior = max (maior, root->val);
        
        if (root->left != nullptr)
            procurar (root->left, maior);
        if (root->right != nullptr)
            procurar (root->right, maior);
    } // procurar
public:
    int goodNodes(TreeNode* root) {
        if (root != nullptr)
            procurar (root, root->val);
        return contar;
    }
};

