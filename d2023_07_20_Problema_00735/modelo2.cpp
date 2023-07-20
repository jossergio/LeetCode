class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pilha;
        for (int a: asteroids) {
            if (pilha.empty ())
                pilha.push (a);
            else {
                if ((pilha.top () * a) > 0) // São do mesmo sinal
                    pilha.push (a);
                else {
                    if (pilha.top () < 0) { // Consequentemente, a > 0; seguem em sentido de afastamento
                        pilha.push (a);
                    } else { // Seguem em sentido de encontro
                        while (!pilha.empty () && ((pilha.top () * a) < 0) && (abs (a) > abs (pilha.top ())))
                            pilha.pop ();
                        if (pilha.empty () || ((pilha.top () * a) > 0))
                            pilha.push (a);
                        else {
                            if (((a * pilha.top ()) < 0) && (abs (a) == abs (pilha.top ())))
                                pilha.pop ();
                        }
                    }
                }
            }
        }
        int pos = pilha.size (); // Vê se entende a lógica, no laço abaixo
        vector<int> resposta (pos);
        while (!pilha.empty ()) {
            resposta [--pos] = pilha.top ();
            pilha.pop ();
        }
        return resposta;
    }
};

