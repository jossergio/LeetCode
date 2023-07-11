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
private:
    void montarGrafo (map<int, vector<int>>& g, TreeNode* no) {
        if (no != nullptr) {
            if (no->left != nullptr) {
                g [no->val].push_back (no->left->val);
                g [no->left->val].push_back (no->val);
                montarGrafo (g, no->left);
            }
            if (no->right != nullptr) {
                g [no->val].push_back (no->right->val);
                g [no->right->val].push_back (no->val);
                montarGrafo (g, no->right);
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) // Nem faz nada; resposta pronta
            return vector<int> (1, target->val);
        map<int, vector<int>> grafo;
        montarGrafo (grafo, root);
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

