class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        deque<pair<char, int>> fila;
        
        for (char c: s) {
            
            if (fila.empty () || fila.back ().first != c)
                fila.push_back ({c, 1});
            else {
                fila.back ().second++;
            }
            
            if (fila.back ().second == k) {
                fila.pop_back ();
            }
        }
        
        string resposta;
        
        while (!fila.empty ()) {
            
            pair<char, int> tmp = fila.front ();
            
            fila.pop_front ();
            
            // while (tmp.second-- > 0)
                resposta.append (tmp.second, tmp.first);
        }
        
        return resposta;
    }
};

