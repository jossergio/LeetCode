class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> pilhaOperandos; // Já guarda convertido
        long tmp1, tmp2; // Para não declarar dentro de blocos
        for (string item: tokens) {
            switch (item [0]) { // Pelo 1o caractere, já sabemos do que se trata
                case '+':
                    tmp1 = pilhaOperandos.top ();
                    pilhaOperandos.pop ();
                    tmp2 = pilhaOperandos.top ();
                    pilhaOperandos.pop ();
                    pilhaOperandos.push (tmp2 + tmp1);
                    break;
                case '-':
                    if (item.size () == 1) { // É só o operador
                        tmp1 = pilhaOperandos.top ();
                        pilhaOperandos.pop ();
                        tmp2 = pilhaOperandos.top ();
                        pilhaOperandos.pop ();
                        pilhaOperandos.push (tmp2 - tmp1);
                    } else { // É um número negativo
                        pilhaOperandos.push (stoi (item));
                    }
                    break;
                case '*':
                    tmp1 = pilhaOperandos.top ();
                    pilhaOperandos.pop ();
                    tmp2 = pilhaOperandos.top ();
                    pilhaOperandos.pop ();
                    pilhaOperandos.push (tmp2 * tmp1);
                    break;
                case '/':
                    tmp1 = pilhaOperandos.top ();
                    pilhaOperandos.pop ();
                    tmp2 = pilhaOperandos.top ();
                    pilhaOperandos.pop ();
                    pilhaOperandos.push (tmp2 / tmp1);
                    break;
                default: // Só restou número inteiro positivo
                    pilhaOperandos.push (stoi (item));
            }
        }
        return (int) pilhaOperandos.top ();
    }
};

