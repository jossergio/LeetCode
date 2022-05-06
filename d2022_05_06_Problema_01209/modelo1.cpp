class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char, int>> pilha;
        
        for (char c: s) {
            
            if (pilha.empty () || pilha.top ().first != c)
                pilha.push ({c, 1});
            else {
                pilha.top().second++;
            }
            
            if (pilha.top ().second == k) {
                pilha.pop ();
            }
        }
        
        stack<char> aux;
        
        while (!pilha.empty ()) {
            
            pair<char, int> tmp = pilha.top ();
            
            pilha.pop ();
            
            while (tmp.second-- > 0)
                aux.push (tmp.first);
        }
        
        string resposta;
        
        while (!aux.empty ()) {
            resposta.push_back (aux.top ());
            aux.pop ();
        }
        
        return resposta;
    }
};

