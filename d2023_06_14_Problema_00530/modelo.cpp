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
    void emOrdem (TreeNode* no, vector<int>& v) {
        if (no != nullptr) {
            emOrdem (no->left, v);
            v.push_back (no->val);
            emOrdem (no->right, v);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> ordenado;
        emOrdem (root, ordenado);
        int minimo = ordenado [1] - ordenado [0];
        for (int i = 2; i < ordenado.size (); i += 1)
            minimo = min (minimo, ordenado [i] - ordenado [i - 1]);
        return minimo;
    }
};

