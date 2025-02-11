class Solution {
public:
    string clearDigits(string s) {
        vector<char> pilha; // Facilita a resposta, em vez de stack
        for (char c: s) {
            if (c >= '0' && c <= '9') {
                if (!pilha.empty () && !(pilha.back () >= '0' && pilha.back () <= '9')) pilha.pop_back ();
                else pilha.push_back (c);
            } else pilha.push_back (c);
        }
        return string (pilha.begin (), pilha.end ());
    }
};
