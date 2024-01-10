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
    int maximo (unordered_map<int, list<int>>& g, int no, int anterior) {
        int m = 0;
        for (int n: g [no])
            if (n != anterior)
                m = max (m, 1 + maximo (g, n, no)); // no fica como anterior
        return m;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, list<int>> grafo;
        queue<TreeNode*> tmp;
        tmp.push (root);
        while (!tmp.empty ()) {
            int k = tmp.size ();
            while (k > 0) {
                TreeNode* t = tmp.front ();
                tmp.pop ();
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
        return maximo (grafo, start, start); // Repete, aqui, como se anterior fosse
    }
};

