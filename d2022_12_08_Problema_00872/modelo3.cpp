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
    void buscar (TreeNode* no, vector<int> &folhas) {
        if (no) {
            if (no->left || no->right) { // Não é folha; precisa descere
                buscar (no->left, folhas);
                buscar (no->right, folhas);
            } else // É folha
                folhas.push_back (no->val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> folhas1;
        vector<int> folhas2;
        buscar (root1, folhas1);
        buscar (root2, folhas2);
        return folhas1 == folhas2;
    }
};

