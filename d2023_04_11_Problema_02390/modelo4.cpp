class Solution {
public:
    string removeStars(string s) {
        string resposta (s.size (), ' ');
        int pos = 0; // Irá apontar a próxima posição de inserçao (alteração)
        for (char c: s)
            if (c == '*')
                pos -= 1;
            else
                resposta [pos++] = c;
        return resposta.substr (0, pos);
    }
};

