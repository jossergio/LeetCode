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
public:
    void flatten(TreeNode* root) {
        
        if (root) {
            TreeNode* esquerda = root->left;
            flatten (esquerda);
            root->left = nullptr;
            
            TreeNode* direita = root->right;
            flatten (direita);
            root->right = esquerda;
            
            TreeNode* tmp = root;
        
            while (tmp->right)
                tmp = tmp->right;
            
            tmp->right = direita;
        } // if
    }
};

