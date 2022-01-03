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
    int maxProfundo (TreeNode *no, int maiorLocal, int menorLocal) {
        if (no == nullptr)
            return maiorLocal - menorLocal;
        
        return max (
            maxProfundo (no->left,
                         max (maiorLocal, no->val),
                         min (menorLocal, no->val)
                        ),
            maxProfundo (no->right,
                        max (maiorLocal, no->val),
                        min (menorLocal, no->val)
                        )
            ); // return max
    } // maxProfundo
    
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return maxProfundo (root, root->val, root->val);
    }
};

