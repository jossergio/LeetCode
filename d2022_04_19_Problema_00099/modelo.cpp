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
    TreeNode* getMaior (TreeNode* no, TreeNode* v) {
        if (no != nullptr) {
            if (no->val > v->val) {
                TreeNode* tmp = getMaior (no, no);
                if (tmp == nullptr)
                    return no;
                else
                    return tmp;
            }
            TreeNode* tmp = getMaior (no->left, v);
            if (tmp != nullptr)
                return tmp;
            return getMaior (no->right, v);
        }
        return nullptr;
    }
    
    TreeNode* getMenor (TreeNode* no, TreeNode* v) {
        if (no != nullptr) {
            if (no->val < v->val) {
                TreeNode* tmp = getMenor (no, no);
                if (tmp == nullptr)
                    return no;
                else
                    return tmp;
            }
            TreeNode* tmp = getMenor (no->right, v);
            if (tmp!= nullptr)
                return tmp;
            return getMenor (no->left, v);
        }
        return nullptr;
    }
    
    bool varrerPreOrdem (TreeNode* no) {
        if (no == nullptr)
            return false;
        TreeNode* esquerdo = getMaior (no->left, no);
        TreeNode* direito = getMenor (no->right, no);
        if (esquerdo != nullptr && direito != nullptr) {
            int tmp = esquerdo->val;
            esquerdo->val = direito->val;
            direito->val = tmp;
            return true;
        }
        if (esquerdo == nullptr && direito == nullptr)
            return varrerPreOrdem (no->left) || varrerPreOrdem (no->right);
        int t = no->val;
        if (esquerdo == nullptr) {
            no->val = direito->val;
            direito->val = t;
        } else {
            no->val = esquerdo->val;
            esquerdo->val = t;
        }
        return true;
    }
    
public:
    void recoverTree(TreeNode* root) {
        varrerPreOrdem (root);
    }
};

