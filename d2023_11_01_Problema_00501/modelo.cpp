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
    void buscar (TreeNode* no, unordered_map<int, int>& cont) {
        if (no != nullptr) {
            cont [no->val] += 1;
            buscar (no->left, cont);
            buscar (no->right, cont);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> cont;
        buscar (root, cont);
        map<int, vector<int>> pre;
        for (auto [v, t]: cont)
            pre [t].push_back (v);
        auto b = pre.rbegin ();
        int m = b->first;
        vector<int> resposta;
        while (b != pre.rend () && m == b->first) {
            resposta.insert (resposta.end (), b->second.begin(), b->second.end ());
            b++;
        }
        return resposta;
    }
};

