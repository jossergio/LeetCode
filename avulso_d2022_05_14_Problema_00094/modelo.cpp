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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> retorno;
        if (root != nullptr) {
            vector<int> tmp = inorderTraversal (root->left);
            retorno.insert (retorno.end (), tmp.begin (), tmp.end ());
            retorno.push_back (root->val);
            tmp.clear ();
            tmp = inorderTraversal (root->right);
            retorno.insert (retorno.end (), tmp.begin (), tmp.end ());
        }
        return retorno;
    }
};

