/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original != nullptr)
            if (original == target) {
                return cloned;
            } else {
                if (TreeNode* tmp = getTargetCopy (original->left, cloned->left, target))
                    return tmp;
                else
                    return getTargetCopy (original->right, cloned->right, target);
            }
        // else
        return nullptr;
    }
};

