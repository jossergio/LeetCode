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
    void emOrdem (vector<int>& v, TreeNode* no) {
        if (no != nullptr) {
            emOrdem (v, no->left);
            v.push_back (no->val);
            emOrdem (v, no->right);
        }
    }
    TreeNode* leitor (vector<int>& v, int i, int j) {
        if (i > j)
            return nullptr;
        // else
        int meio = (i + j) / 2;
        return new TreeNode (v [meio], leitor (v, i, meio - 1), leitor (v, meio + 1, j));
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        emOrdem (v, root);
        return leitor (v, 0, v.size () - 1);
    }
};

