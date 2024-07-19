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
    void buscar (TreeNode* topo, map<TreeNode*, vector<TreeNode*>>& grafo, map<TreeNode*, bool>& visitados, TreeNode* atual, int contador, int& resposta) {
        if (!visitados [atual]) {
            if (contador < 0)
                return; // Sumariamente; atingido o limite
            if (grafo [atual].size () == 1 && atual != topo) { // É uma folha; e não é root (topo)
                resposta += 1;
                return; // Não precisa fazer nada depois daqui; evitar o else
            }
            // else
            visitados [atual] = true;
            for (TreeNode* a: grafo [atual]) {
                buscar (topo, grafo, visitados, a, contador - 1, resposta);
            }
            visitados [atual] = false;
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*, vector<TreeNode*>> grafo;
        map<TreeNode*, bool> visitados;
        queue<TreeNode*> fila;
        TreeNode* topo = root; // Precisarei desse cara mais adiante
        fila.push (root);
        while (!fila.empty ()) {
            TreeNode* tmp = fila.front ();
            fila.pop ();
            if (tmp->left != nullptr) {
                fila.push (tmp->left);
                grafo [tmp].push_back (tmp->left);
                grafo [tmp->left].push_back (tmp);
            }
            if (tmp->right != nullptr) {
                fila.push (tmp->right);
                grafo [tmp].push_back (tmp->right);
                grafo [tmp->right].push_back (tmp);
            }
        }
        int resposta = 0;
        for (auto [no, proximos]: grafo) {
            if (proximos.size () == 1 && no != topo) { // Só tem o ancestral; ou seja, é uma folha; e não é root (topo)
                cout << "Vou testar " << no->val << endl;
                visitados [no] = true;
                buscar (topo, grafo, visitados, proximos [0], distance - 1, resposta);
                visitados [no] = false;
            }
        }
        return resposta / 2; // Pois fez os caminhso indo e vindo e eu não quis complicar, fazendo gerenciamento disso
    }
};

