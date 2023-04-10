class Solution {
public:
    bool isValid(string s) {
        
        stack<char> pilha;
        unordered_map<char, char> tabela = {{'}','{'}, {']', '['}, {')', '('}};
        
        for (string::iterator c = s.begin (); c != s.end (); c++) {
            switch (*c) {
                case '{':
                case '[':
                case '(':
                    pilha.push (*c);
                    break;
                case '}':
                case ']':
                case ')':
                    if (!pilha.empty () && pilha.top () == tabela [*c])
                        pilha.pop ();
                    else
                        return false;
                    break;
            } // switch
        } // for
    
    return (pilha.empty ());
    }
};

