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
    void inOrder (TreeNode* no, vector<int>& v) {
        if (no) {
            inOrder (no->left, v);
            v.push_back (no->val);
            inOrder (no->right, v);
        }
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> vetor; // Após a Leitura, já estará ordenado
        inOrder (root, vetor);
        int minimo = vetor [1] - vetor [0]; // Na definição do problema, há, pelo menos, dois
        for (int i = 2; i < vetor.size (); i += 1)
            minimo = min (minimo, vetor [i] - vetor [i - 1]);
        return minimo;
    }
};

