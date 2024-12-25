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
    int processar (vector<int>& v) {
        const size_t t = v.size ();
        int contagem = 0;
        for (int a = 0; a < t; a += 1) {
            int menor = v [a]; // Pressupõe
            int i_menor = a;
            for (int b = a + 1; b < t; b += 1) {
                if (v [b] < menor) {
                    i_menor = b;
                    menor = v [b];
                }
            }
            if (i_menor != a) { // Há troca a fazer
                contagem += 1;
                swap (v [i_menor], v [a]);
            }
        }
        return contagem;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> fila;
        fila.push (root);
        vector<int> nivel;
        int resposta = 0;
        while (!fila.empty ()) {
            int t = fila.size ();
            TreeNode* tmp; // Para não ficar alocando dentro do laço
            while (t-- > 0) {
                tmp = fila.front ();
                fila.pop ();
                if (tmp->left != nullptr) {
                    nivel.push_back (tmp->left->val);
                    fila.push (tmp->left);
                }
                if (tmp->right != nullptr) {
                    nivel.push_back (tmp->right->val);
                    fila.push (tmp->right);
                }
            }
            resposta += processar (nivel);
            nivel.clear (); // Prepara para o próximo
        }
        return resposta;
    }
};

