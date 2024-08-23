using Fracao = struct {
    int numerador; // Conterá, também, o sinal
    int denominador;
}; // Fracao

class Solution {
private:
    Fracao pegar_fracao (string e, int& p) { // Fará de modo de autômato
        Fracao f;
        if (e [p] == '-') {
            f.numerador = -1; // Só para já conter o sinal
        } else {
            f.numerador = 1; // Sinal positivo
        }
        p += 1; // Salta o sinal
        string tmp;
        while (e [p] != '/') {
            tmp += e [p++];
        }
        p += 1; // Pula o /
        f.numerador *= atoi (tmp.c_str ()); // Para incluir o sinal
        tmp = "";
        while (p < e.size () && e [p] != '-' && e [p] != '+') {
            tmp += e [p++];
        }
        f.denominador = atoi (tmp.c_str ());
        return f;
    }

    int mdc (int a, int b) { // Sempre virão positivos
        if (a < b) swap (a, b);
        while (b != 0) {
            int resto = a % b;
            a = b;
            b = resto;
        }
        return a;
    }

    int mmc (int a, int b) { // Idem sobre positivos
        return abs ((a * b) / mdc (a, b));
    }

    Fracao reduzir (Fracao f) {
        int sinal = f.numerador < 0 ? -1 : 1; // Guarda o sinal
        f.numerador = abs (f.numerador); // Desconsidera o sinal
        int m = mdc (f.numerador, f.denominador);
        f.numerador /= m;
        f.numerador *= sinal;
        f.denominador /= m;
        return f;
    }

    string para_texto (Fracao f) {
        return to_string (f.numerador) + "/" + to_string (f.denominador);
    }

public:
    string fractionAddition(string expression) {
        if (expression [0] != '-' && expression [0] != '+') expression = "+" + expression; // Para sempre contar um sinal no início
        int p = 0;
        Fracao fracao = pegar_fracao (expression, p);
        while (p < expression.size ()) {
            Fracao tmp = pegar_fracao (expression, p);
            int m = mmc (fracao.denominador, tmp.denominador);
            fracao.numerador = ((m / fracao.denominador) * fracao.numerador) + ((m / tmp.denominador) * tmp.numerador);
            fracao.denominador = m;
        }
        return para_texto (reduzir (fracao));
    }
};

