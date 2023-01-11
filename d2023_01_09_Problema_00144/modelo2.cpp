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
    void varrerPreOrdem (TreeNode* no, vector<int>& resposta) {
        if (no) { // not nullptr
            resposta.push_back (no->val);
            varrerPreOrdem (no->left, resposta);
            varrerPreOrdem (no->right, resposta);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> resposta;
        varrerPreOrdem (root, resposta);
        return resposta;
    }
};

