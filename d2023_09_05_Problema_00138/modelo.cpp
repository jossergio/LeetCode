/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> memo; // Será um rascunho, um projeto, mas será um memoization
        
        function<Node* (Node*)> buscar = [&] (Node* no) -> Node* {
            if (no == nullptr)
                return nullptr; // Nem precisa fazer nada
            // else
            cout << no->val << endl;
            if (memo.count (no) == 0) { // Ainda não gerou
                memo [no] = new Node (no->val);
                memo [no]->next = buscar (no->next);
                memo [no]->random = buscar (no->random);
                // Mesmo que ambos sejam nullptr
            }
            return memo [no];
        }; // function buscar
        
        Node* resposta = new Node {0}; // Qualquer valor; será descartado, mesmo
        resposta->next = buscar (head); // Para evitar controlar nullptr etc; algoritmo simples
        return resposta->next;
    }
};

