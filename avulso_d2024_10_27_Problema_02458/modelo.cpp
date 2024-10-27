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

using Niveis = unordered_map<int, vector<pair<int, int>>>; // Lista dos nós em cada nível e seus repectivos totais ineriores
using Nos = unordered_map<int, pair<int, int>>; // índice = nó; first = nível; second = níveis inferiores (total)

class Solution {
private:
    static bool ordem (const pair<int, int>& a, const pair <int, int>& b) {
        return a.second > b.second;
    }
    int montar (TreeNode* no, Niveis& n, Nos& nos, int nivel) {
        if (no == nullptr) return 0;
        // else
        int m = max (montar (no->left, n, nos, nivel + 1), montar (no->right, n, nos, nivel + 1));
        n [nivel].push_back (make_pair (no->val, m));
        nos [no->val] = make_pair (nivel, m);
        return m + 1; // Adiciona o próprio nível
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        Niveis niveis;
        Nos niveis_nos;

        int m = max (montar (root->left, niveis, niveis_nos, 1), montar (root->right, niveis, niveis_nos, 1));
        niveis [0].push_back (make_pair (root->val, m));
        niveis_nos [root->val] = make_pair (0, m);

        for (auto [n, v]: niveis) sort (niveis [n].begin (), niveis [n].end (), ordem);

        vector<int> resposta;
        resposta.reserve (queries.size ()); // Já sabemos o tamanho da resposta; valor inerte
        for (int q: queries) {
            int r = niveis_nos [root->val].second; // O maior nível da árvore;
            int nivel = niveis_nos [q].first;
            if (niveis [nivel][0].first == q) { // Se o maior for o próprio nó
                if (niveis [nivel].size () == 1) r -= niveis [nivel][0].second + 1; // Também tira o próprio nível
                else r -= niveis [nivel][0].second - niveis [nivel][1].second; // Retira a diferança para o segundo
            // Obs.: caso haja empate com o maior sendo o nível objeto, o cálculo anterior não fará diferença
            // Obs.: notar que se for o maior e houve outro igual, não fará diferença, ao final, independente da ordem
            }
            resposta.push_back (r);
        }
        return resposta;
    }
};

