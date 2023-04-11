class Solution {
public:
    string removeStars(string s) {
        string resposta;
        for (char c: s)
            if (c == '*')
                resposta.pop_back ();
            else
                resposta.push_back (c);
        return resposta;
    }
};

