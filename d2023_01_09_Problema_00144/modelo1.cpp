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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> retorno;
        if (!root) // nullptr
            return retorno; // Vazio
        retorno.push_back (root->val);
        vector<int> esquerda = preorderTraversal (root->left);
        vector<int> direita = preorderTraversal (root->right);
        retorno.insert (retorno.end (), esquerda.begin (), esquerda.end ());
        retorno.insert (retorno.end (), direita.begin (), direita.end ());
        return retorno;
    }
};

