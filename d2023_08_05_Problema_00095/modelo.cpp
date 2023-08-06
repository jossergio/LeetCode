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
    vector<TreeNode*> arvores (int i, int j, map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> resposta;
        if (i > j) {
            resposta.emplace_back (nullptr);
        } else {
            if (memo.find (make_pair (i, j)) != memo.end ())
                return memo [make_pair (i, j)];
        }
        // else
        for (int k = i; k <= j; k += 1) {
            vector<TreeNode*> esquerda = arvores (i, k - 1, memo);
            vector<TreeNode*> direita = arvores (k + 1, j, memo);
            for (auto esq: esquerda) {
                for (auto dir: direita) {
                    TreeNode* raizLocal = new TreeNode (k, esq, dir);
                    resposta.emplace_back (raizLocal);
                }
            }
        }
        return memo [make_pair (i, j)] = resposta;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return arvores (1, n, memo);
    }
};

