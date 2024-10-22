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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> linhas;
        linhas.push (root); // Há, pelo menos, dois nós, pela definição do problema
        vector<long long> somas;
        while (!linhas.empty ()) {
            size_t q = linhas.size ();
            long long soma = 0;
            while (q-- > 0) {
                TreeNode* tmp = linhas.front ();
                linhas.pop ();
                soma += tmp->val;
                if (tmp->left != nullptr) linhas.push (tmp->left);
                if (tmp->right != nullptr) linhas.push (tmp->right);
            }
            somas.push_back (soma);
        }
        sort (somas.begin (), somas.end (), greater<long long> ());
        return k <= somas.size () ? somas [k - 1] : -1; // 0-begin x 1-begin
    }
};

