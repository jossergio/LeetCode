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
    void ajudante (TreeNode* no, vector<int>& lista) {
        if (no) {
            ajudante (no->left, lista);
            lista.push_back (no->val);
            ajudante (no->right, lista);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int> tmp;
        
        ajudante (root, tmp);
        
        for (int i = 1; i < tmp.size (); i++)
            if (tmp [i - 1] >= tmp [i])
                return false;
        
        return true;
    }
};

