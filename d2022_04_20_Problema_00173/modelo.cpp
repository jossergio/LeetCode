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
class BSTIterator {
private:
    vector<int> elementos;
    int indice;
    
    void montarElementos (TreeNode* no) {
        if (no != nullptr) {
            montarElementos (no->left);
            elementos.push_back (no->val);
            montarElementos (no->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        elementos.clear ();
        montarElementos (root);
        indice = 0;
    }
    
    int next() {
        return elementos [indice++];
    }
    
    bool hasNext() {
        return indice < elementos.size ();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

