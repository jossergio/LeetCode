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
    int maximo (unordered_map<int, list<int>>& g, int no, vector<bool>& visitados) {
        int m = 0;
        visitados [no] = true;
        for (int n: g [no])
            if (!visitados [n])
                m = max (m, 1 + maximo (g, n, visitados));
        visitados [no] = false;
        return m;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, list<int>> grafo;
        queue<TreeNode*> tmp;
        tmp.push (root);
        int maior = root->val; // Pressupõe
        while (!tmp.empty ()) {
            int k = tmp.size ();
            while (k > 0) {
                TreeNode* t = tmp.front ();
                tmp.pop ();
                maior = max (maior, t->val);
                if (t->left != nullptr) {
                    grafo [t->val].push_back (t->left->val);
                    grafo [t->left->val].push_back (t->val);
                    tmp.push (t->left);
                }
                if (t->right != nullptr) {
                    grafo [t->val].push_back (t->right->val);
                    grafo [t->right->val].push_back (t->val);
                    tmp.push (t->right);
                }
                k -= 1;
            } // while k
        } // while !tmp.empty
        vector<bool> visitados (maior, false);
        return maximo (grafo, start, visitados);
    }
};

