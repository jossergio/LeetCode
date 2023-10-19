class Solution {
private:
    void push (stack<char>& p, char c) {
        if (c == '#') {
            if (!p.empty ())
                p.pop ();
        } else
            p.push (c);
    }
public:
    bool backspaceCompare(string s, string t) {
        stack<char> pilha1, pilha2;
        const int ts = s.size (), tt = t.size ();
        int is = 0, it = 0;
        while (is < ts || it < tt) {
            if (is < ts) { // Tem que saber se esse não passou, pois correm individualmente
                push (pilha1, s [is]);
                is += 1;
            }
            if (it < tt) { // idem
                push (pilha2, t [it]);
                it += 1;
            }
        }
        if (pilha1.size () != pilha2.size ()) // Tamanhos diferentes não podem ter elementos iguais em sequência
            return false;
        while (!pilha1.empty ()) { // Qualquer das pilhas; correm iguais
            if (pilha1.top () != pilha2.top ())
                return false; // Direto
            pilha1.pop ();
            pilha2.pop ();
        }
        return true; // Passou por todos os testes e não encontrou diferença
    }
};

