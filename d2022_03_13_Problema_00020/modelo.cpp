class Solution {
public:
    bool isValid(string s) {
        
        stack<char> pilha;
        
        for (string::iterator c = s.begin (); c != s.end (); c++) {
            switch (*c) {
                case '{':
                case '[':
                case '(':
                    pilha.push (*c);
                    break;
                case '}':
                    if (!pilha.empty () && pilha.top () == '{')
                        pilha.pop ();
                    else
                        return false;
                    break;
                case ']':
                    if (!pilha.empty () && pilha.top () == '[')
                        pilha.pop ();
                    else
                        return false;
                    break;
                case ')':
                    if (!pilha.empty () && pilha.top () == '(')
                        pilha.pop ();
                    else
                        return false;
                        
            } // switch
        } // for
    
    return (pilha.empty ());
    }
};

