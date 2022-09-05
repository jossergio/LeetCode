/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> resp;
        queue<Node*> fila;
        
        if (root)
            fila.push (root);
        else
            return resp; // Vazio; teria que ter pelo menos um para prosseguir
        
        while (!fila.empty ()) {
            
            int leitura = fila.size ();
            vector<int> tmp;
            
            for (int i = 0; i < leitura; i++) {
                Node* proximo = fila.front ();
                fila.pop ();
                tmp.push_back (proximo->val);
                for (auto filho: proximo->children)
                    fila.push (filho);
            }
            
            resp.emplace_back (tmp);
        }
        
        return resp;
    }
};

