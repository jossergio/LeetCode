class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map <string, function <long (long, long)>> calculos;
        calculos ["+"] = plus ();
        calculos ["-"] = minus ();
        calculos ["*"] = multiplies ();
        calculos ["/"] = divides ();
        stack<long> pilhaOperandos; // Já guarda convertido
        for (string item: tokens) {
            auto calculo = calculos.find (item);
            if (calculo != calculos.end ()) { // É um operador
                long operando1 = pilhaOperandos.top ();
                pilhaOperandos.pop ();
                long operando2 = pilhaOperandos.top () ;
                pilhaOperandos.pop ();
                pilhaOperandos.push (calculo->second (operando2, operando1));
            } else { // É um operando
                pilhaOperandos.push (stol (item));
            }
        }
        return pilhaOperandos.top (); // Só sobra um; o problema diz que é uma expressao válida
    }
};

