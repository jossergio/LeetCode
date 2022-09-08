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
    string tree2str(TreeNode* root) {
        
        string retorno = "";
        char tmp [10]; // Auxiliar na conversão
        
        if (root) {
            sprintf (tmp, "%d", root->val);
            retorno = string (tmp);
            
            if (root->right) {
                retorno = retorno + "(" + tree2str (root->left) + ")";
                retorno = retorno + "(" + tree2str (root->right) + ")";
            } else {
                if (root->left)
                    retorno = retorno + "(" + tree2str (root->left) + ")";
            }
        }
        
        return retorno;
    }
};

