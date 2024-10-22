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
    void buscar (TreeNode* no, int nivel, map<int, long long>& m) {
        if (no != nullptr) {
            m [nivel] += no->val;
            if (no->left != nullptr) buscar (no->left, nivel + 1, m);
            if (no->right != nullptr) buscar (no->right, nivel + 1, m);
        }
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int, long long> mapa;
        buscar (root, 1, mapa);
        vector<long long> somas;
        somas.reserve (mapa.size ());
        for (auto m: mapa) somas.push_back (m.second);
        sort (somas.begin (), somas.end (), greater<long long> ());
        return k <= somas.size () ? somas [k - 1] : -1; // 0-begin x 1-begin
    }
};

