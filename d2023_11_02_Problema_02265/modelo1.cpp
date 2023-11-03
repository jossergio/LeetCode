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
    void buscar (TreeNode* no, long& soma, int& divisor, int& contar) {
        if (no != nullptr) {
            long s1 = 0;
            long s2 = 0;
            int d1 = 0;
            int d2 = 0;
            buscar (no->left, s1, d1, contar);
            buscar (no->right, s2, d2, contar);
            soma = s1 + s2 + no->val;
            divisor = d1 + d2 + 1;
            if (no->val == (soma / divisor))
                contar += 1;
        }
    }
public:
    int averageOfSubtree(TreeNode* root) {
        long soma = 0;
        int divisor = 0;
        int contar = 0;
        buscar (root, soma, divisor, contar);
        return contar;
    }
};

