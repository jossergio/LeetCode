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
    vector<int> lista;
    void ajudante (TreeNode* no) {
        if (no) {
            ajudante (no->left);
            lista.push_back (no->val);
            ajudante (no->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        
        lista.clear ();
        
        ajudante (root);
        
        for (int i = 1; i < lista.size (); i++)
            if (lista [i - 1] >= lista [i])
                return false;
        
        return true;
    }
};

