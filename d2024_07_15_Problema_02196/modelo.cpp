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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mapa;
        set<int> elementos; // Inicialmente, possíveis raízes
        set<int> folhas; // A diferença com elementos indicará a raiz
        for (auto item: descriptions) {
            if (mapa.count (item [0]) == 0) {
                mapa [item [0]] = new TreeNode (item [0]);
            }
            if (mapa.count (item [1]) == 0) {
                mapa [item [1]] = new TreeNode (item [1]);
            }
            if (item [2] == 1) { // Será nó esquerdo
                mapa [item [0]]->left = mapa [item [1]];
            } else { // Será nó direito
                mapa [item [0]]->right = mapa [item [1]];
            }
            elementos.insert (item [0]);
            folhas.insert (item [1]);
        }
        for (int i: folhas) {
            elementos.erase (i);
        }
        return mapa [*elementos.begin ()]; // Só deve ter ficado um
    }
};

