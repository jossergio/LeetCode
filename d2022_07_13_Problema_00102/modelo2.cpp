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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> resposta;
        
        if (root) {
            
            vector<int> tmp;
            queue<TreeNode*> niveis;
            
            niveis.push (root);
            
            while (!niveis.empty ()) {
                
                int qtd = niveis.size ();
                
                for (int i = 0; i < qtd; i++) {
                    
                    TreeNode* item = niveis.front ();
                    tmp.push_back (item->val);
                    
                    niveis.pop ();
                    
                    if (item->left)
                        niveis.push (item->left);
                    
                    if (item->right)
                        niveis.push (item->right);
                }
                
                resposta.push_back (tmp);
                tmp.clear ();
            }
        }
        
        return resposta;
    }
};

