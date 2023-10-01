class Solution {
private:
    string reversoPilha (stack<char>& p, int t) {
        string resposta;
        if (t > 0) {
            resposta.reserve (p.size () + 1);
            resposta.push_back (' ');
        } else
            resposta.reserve (p.size ());
        while (p.size () > 0) {
            resposta.push_back (p.top ());
            p.pop ();
        }
        return resposta;
    }
public:
    string reverseWords(string s) {
        stack<char> pilha;
        string resposta;
        resposta.reserve (s.size ());
        for (char c: s)
            if (c == ' ')
                resposta.append (reversoPilha (pilha, resposta.size ()));
            else
                pilha.push (c);
        resposta.append (reversoPilha (pilha, resposta.size ()));
        return resposta;
    }
};

