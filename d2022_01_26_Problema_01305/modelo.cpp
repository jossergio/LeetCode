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
    
    vector<int> arvoreParaLista (TreeNode *arvore) {
        
        vector<int> v;
        
        if (arvore != nullptr) {
            vector<int> tmp = arvoreParaLista (arvore->left);
            v.insert (v.end (), tmp.begin (), tmp.end ());
            v.push_back (arvore->val);
            tmp = arvoreParaLista (arvore->right);
            v.insert (v.end (), tmp.begin (), tmp.end ());
        }
        
        return v;
    }
    
    vector<int> ordenado (vector<int> l1, vector<int> l2) {
        
        vector<int>::iterator i1 = l1.begin ();
        vector<int>::iterator i2 = l2.begin ();
        
        vector<int> o;
        
        while ((i1 != l1.end ()) && (i2 != l2.end ())) {
            
            if (*i1 < *i2) {
                o.push_back (*i1);
                i1++;
            } else {
                o.push_back (*i2);
                i2++;
            }
            
        }
        
        if (i1 != l1.end ()) { // Poderia ser dispensado e usar diretamente os laços
            
            while (i1 != l1.end ()) {
                o.push_back (*i1);
                i1++;
            }
            
        } else { // Só pode ser o outro
            
            while (i2 != l2.end ()) {
                o.push_back (*i2);
                i2++;
            }
            
        }
        
        return o;
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> lista1 = arvoreParaLista (root1);
        vector<int> lista2 = arvoreParaLista (root2);
        
        return ordenado (lista1, lista2);
    }
};

