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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        int t = 0; // Será o maior nó da árvore
        stack<TreeNode*> pilha; // Faremos uma varredura de forma interativa
        pilha.push (root);
        map<int, vector<pair<int, char>>> grafo;
        while (!pilha.empty ()) {
            TreeNode* tmp = pilha.top ();
            pilha.pop ();
            t = max (t, tmp->val);
            if (tmp->left != nullptr) {
                pilha.push (tmp->left);
                grafo [tmp->val].push_back (make_pair (tmp->left->val, 'L'));
                grafo [tmp->left->val].push_back ({tmp->val, 'U'});
            }
            if (tmp->right != nullptr) {
                pilha.push (tmp->right);
                grafo [tmp->val].push_back ({tmp->right->val, 'R'});
                grafo [tmp->right->val].push_back ({tmp->val, 'U'});
            }
        }
        stack<pair<int, int>> proximo; // Faremos uma varredura interativa do gráfico
        proximo.push ({startValue, 0});
        string resposta;
        vector<bool> visitados (t + 1, false); // Não utilziará a posição zero
        visitados [startValue] = true;
        while (!proximo.empty ()) { // Atingirá o objetivo antes de esvaziar
            auto [a, c] = proximo.top (); // a = atual; c = contador
            proximo.pop ();
            if (c < grafo [a].size ()) {
                auto [p, ch] = grafo [a][c]; // p = próximo; ch = a direção
                if (!visitados [p]) {
                    visitados [p] = true;
                    resposta.push_back (ch);
                    if (p == destValue) {
                        return resposta;
                    }
                    // else
                    proximo.push ({a, c + 1}); // Repõe, o atual, atualizando
                    proximo.push ({p, 0});
                } else { // if !visitados
                    proximo.push ({a, c + 1}); // Não gosto disso, mas a sequência impõe
                }
            } else {
                resposta.pop_back ();
                visitados [a] = false;
            }
        }
        return ""; // Caso... Mas não é para chegar aqui
    }
};

