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
    void varrer (TreeNode* no, map<int, vector<pair<int, int>>>& cols, int col, int nivel) {
        if (no) {
            cols [col].push_back ({nivel, no->val});
            varrer (no->left, cols, col - 1, nivel + 1);
            varrer (no->right, cols, col + 1, nivel + 1);
        }
    }
    
    static bool ordem (pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<pair<int, int>>> colunas;
        
        varrer (root, colunas, 0, 0);
        
        vector<vector<int>> resp;
        
        for (auto& c: colunas) {
            sort (c.second.begin (), c.second.end (), ordem);
            
            vector<int> tmp;
            
            for (auto& v: c.second)
                tmp.push_back (v.second); // Segundo valor do segundo valor
            
            resp.emplace_back (tmp);
        }
        
        return resp;
    }
};

