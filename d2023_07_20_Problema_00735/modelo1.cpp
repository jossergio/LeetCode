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
        vector<int> resposta;
        while (!pilha.empty ()) {
            resposta.push_back (pilha.top ());
            pilha.pop ();
        }
        reverse (resposta.begin (), resposta.end ()); // A pilha faz vir de trás para frente
        return resposta;
    }
};

