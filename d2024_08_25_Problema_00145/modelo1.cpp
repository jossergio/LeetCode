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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> resposta;
        if (root != nullptr) {
            for (int a: postorderTraversal (root->left)) resposta.push_back (a);
            for (int a: postorderTraversal (root->right)) resposta.push_back (a);
            resposta.push_back (root->val);
        }
        return resposta;
    }
};

