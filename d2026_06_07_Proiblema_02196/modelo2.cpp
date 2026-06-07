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
        map <int, TreeNode*> mapa;
        set<int> raizes; // Em princípio, todos serão raizes; depois, ajusta
        for (auto item: descriptions) {
            if (mapa.count (item [0]) == 0) {
                mapa [item [0]] = new TreeNode (item [0]);
                raizes.insert (item [0]);
            }
            if (mapa.count (item [1]) == 0) {
                mapa [item [1]] = new TreeNode (item [1]);
            }
        }
        for (auto item: descriptions) {
            if (item [2] == 1) { // Será esquerdo
                mapa [item [0]]->left = mapa [item [1]];
            } else { // Será direito
                mapa [item [0]]->right = mapa [item [1]];
            }
            raizes.erase (item [1]); // Tira a folha da lista de raízes
        }
        return mapa [*raizes.begin ()]; // Só sobrará um
    }
};
