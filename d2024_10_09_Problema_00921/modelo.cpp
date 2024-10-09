class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> pilha;
        for (char c: s) {
            if (pilha.empty () || pilha.top () == c) pilha.push (c);
            else { // Preferi desmembrar uma condição, para a linga não ficar muito grande
                if (pilha.top () == '(' && c == ')') pilha.pop ();
                else pilha.push (c);
            }
        }
        return pilha.size ();
    }
};

