class Solution {
private:
    string expressao;
    stack<int> valores;
    stack<char> operadores;
    int proximoElemento;
    int tipoToken;
    char verToken () {
        if (proximoElemento < expressao.size ())
            return expressao [proximoElemento];
        return 0;
    } // verToken
    
    string getNextToken () {
        string retorno = "";
        switch (char c = verToken ()) {
            case '+':
            case '-':
            case '*':
            case '/':
                    proximoElemento++;
                    tipoToken = 1; // Operador
                    retorno += c; // E já converte
                    break;
            case ' ':
                do {
                    proximoElemento++;
                } while (verToken () == ' ');
                retorno = getNextToken ();
                break;
            case 0:
                tipoToken = -1; // Basicamente, um erro; atingiu o final. Só para constar
                return ""; break;
            default: // Com certeza, é número
                tipoToken = 0; // Número
                retorno += c;
                proximoElemento++;
                while ((c = verToken ()) != 0) // Se 0, final, já sai
                    if (c >= '0' && c <= '9') {
                        retorno += c;
                        proximoElemento++;
                    } else { // if c...
                        break; // Não é mais número
                    } // else if c...
        } // switch verToken
        return retorno;
    } // getNextToken
    
    int verNegativo (int v) {
        // Verificar se tá com acumulado negativo
        if (operadores.size () > 0)
            if (operadores.top () == '-') {
                operadores.pop ();
                operadores.push ('+');
                v = -v;
            } // if if operadores negativo
        return v;
    }
    
    void executar () {
        char operador = operadores.top ();
        operadores.pop (); // pop não retorna o topo; só remove
        int v1 = valores.top ();
        valores.pop ();
        int v2 = valores.top ();
        valores.pop ();
        switch (operador) {
            case '+': valores.push (v1 + v2); break;
            case '-': valores.push (v2 - v1); break;
            case '*': v2 = verNegativo (v2); valores.push (v1 * v2); break;
            case '/': v2 = verNegativo (v2); valores.push (v2 / v1);
            // Não precisa de outro; não há essa possibilidade
        } // switch
    } // executar
    
    void incluirOperador (string e) {
        if (operadores.size () == 0) {
            operadores.push (e [0]); // Só tem o operador e é simples, pela definição do problema
            return; // Só para sair
        }
        char topo = operadores.top (); // top não tira o elemento
        switch (topo) {
            case '+':
            case '-':
                if (e [0] == '+' || e [0] == '-')
                    executar ();
                // O contário, é * ou /; só acumular
                operadores.push (e [0]);
                break;
            case '*':
            case '/':
                executar (); // Indiferente
                operadores.push (e [0]);
        }
    } // incluirOperador
    
    int avaliar () {
        // Obs.: pela definição do problema, não há números negativos
        string elemento;
        while (proximoElemento < expressao.size ()) {
            elemento = getNextToken ();
            switch (tipoToken) {
                case 0: // Número
                    valores.push (stoi (elemento));
                    break;
                case 1: // operador
                    incluirOperador (elemento);
                    break;
                // A outra opção é o -1, final. Mas, não precisa.
            } // switch
        } // while
        while (operadores.size () > 0)
            executar ();
        return valores.top ();
    } // avaliar
    
public:
    int calculate(string s) {
        expressao = s;
        proximoElemento = 0;
        return avaliar ();
    }
};

