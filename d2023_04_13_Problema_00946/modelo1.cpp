class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int colocado = 0, tirado = 0; // Marca posições nos vetores
        stack<int> pilha; // Irá simular a pilha e será utilizado para checagem das sequências
        pilha.push (pushed [colocado++]); // Tem que ter, sempre, o primeiro
        while (colocado < pushed.size ()) {
            if (!pilha.empty () && pilha.top () == popped [tirado]) {
                pilha.pop ();
                tirado += 1;
            } else {
                pilha.push (pushed [colocado++]);
            }
        }
        while (!pilha.empty ()) {
            if (pilha.top () == popped [tirado]) {
                pilha.pop ();
                tirado += 1;
            } else
                return false;
        }
        return true;
    }
};

