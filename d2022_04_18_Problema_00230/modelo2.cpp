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
    void emOrdem (TreeNode *no, vector<int> &v) {
        if (no != nullptr) {
            emOrdem (no->left, v);
            v.push_back (no->val);
            emOrdem (no->right, v);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> lista;
        
        emOrdem (root, lista);
        
        return lista [k - 1];
    }
};

