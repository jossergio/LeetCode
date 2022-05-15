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
    void somar (TreeNode* root, int nivel, vector<int>& somas) {
        
        if (root == nullptr)
            return;

        while (nivel > (somas.size () - 1))
            somas.push_back (0); // Elemento neutro da adição
        
        somas [nivel] += root->val;
        somar (root->left, nivel + 1, somas);
        somar (root->right, nivel + 1, somas);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<int> s;
        s.push_back (0); // Se root for nullptr, pelo menos já temos um valor
        somar (root, 0, s);
        return s [s.size () - 1];
    }
};

