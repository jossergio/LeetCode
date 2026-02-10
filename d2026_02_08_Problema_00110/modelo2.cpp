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
    int altura (TreeNode* no) {
        if (no == nullptr) return 0;
        int esq = altura (no->left);
        if (esq == -1) return -1; // Propaga
        // Para agilizar, só testa o outro lado se o primeiro passar
        int dir = altura (no->right);
        if (dir == -1) return -1; // Idem
        if (abs (esq - dir) > 1) return -1;
        return 1 + max (esq, dir);
    }
public:
    bool isBalanced(TreeNode* root) {
        return altura (root) != -1;
    }
};
