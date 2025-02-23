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
class FindElements {
private:
    set<int> valores;
    void montar (TreeNode* no, int v) {
        if (no != nullptr) {
            valores.insert (v);
            montar (no->left, 2 * v + 1);
            montar (no->right, 2 * v + 2);
        }
    }
public:
    FindElements(TreeNode* root) {
        montar (root, 0);
    }
    
    bool find(int target) {
        return valores.count (target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
