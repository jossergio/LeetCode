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
    int minDepth(TreeNode* root) {
        if (!root) // nullptr
            return 0;
        int nivel = 0;
        function<void (TreeNode*, int)> buscar;
        buscar = [&nivel, &buscar] (TreeNode* no, int n) -> void {
            if (!no->left && !no->right) { // Folha
                if (nivel == 0 || n < nivel)
                    nivel = n;;
                return; // Evita o else
            }
            if (no->left)
                buscar (no->left, n + 1);
            if (no->right)
                buscar (no->right, n + 1);
        };
        buscar (root, 1);
        return nivel;
    }
};

