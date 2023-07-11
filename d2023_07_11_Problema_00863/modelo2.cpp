/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) // Nem faz nada; resposta pronta
            return vector<int> (1, target->val);
        map<int, vector<int>> grafo;
        auto montarGrafo = [&grafo, &root] () -> void {
            queue<TreeNode*> f;
            f.push (root);
            while (!f.empty ()) {
                int t = f.size ();
                while (t-- > 0) {
                    TreeNode* atual = f.front ();
                    if (atual->left != nullptr) {
                        grafo [atual->val].push_back (atual->left->val);
                        grafo [atual->left->val].push_back (atual->val);
                        f.push (atual->left);
                    }
                    if (atual->right != nullptr) {
                        grafo [atual->val].push_back (atual->right->val);
                        grafo [atual->right->val].push_back (atual->val);
                        f.push (atual->right);
                    }
                    f.pop ();
                }
            }
        };
        montarGrafo ();
        queue<int> fila;
        set<int> visitados;
        fila.push (target->val); // Sempre há o primeiro
        visitados.insert (target->val);
        vector<int> resposta; // Para já jogar o vazio
        while (k > 0 && !fila.empty ()) {
            int t = fila.size ();
            while (t-- > 0) {
                for (int prox: grafo [fila.front ()])
                    if (visitados.count (prox) == 0) {
                        fila.push (prox);
                        visitados.insert (prox);
                    }
                fila.pop ();
            }
            k -= 1;
            if (k == 0) // chegou ao final
                while (!fila.empty ()) { // Ao esvaziar a fila, também sai do laço principal; k == 0 também
                    int t = fila.front ();
                    fila.pop ();
                    resposta.push_back (t);
                }
        }
        return resposta;
    }
};

