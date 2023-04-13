class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int colocado = 0, tirado = 0; // Marca posições nos vetores
        stack<int> pilha; // Irá simular a pilha e será utilizado para checagem das sequências
        while (colocado < pushed.size ()) {
            pilha.push (pushed [colocado++]);
            while (!pilha.empty () && pilha.top () == popped [tirado]) {
                pilha.pop ();
                tirado += 1;
            }
        }
        return pilha.size () == 0;
    }
};

