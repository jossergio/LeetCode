class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int contagem = 0; // Para ser utilizado para checar se a fila entrou em laço infinito
        queue<int> estudantes;
        int i = 0; // Aponta para o topo da pilha de sanduíches
        for (int a: students)
            estudantes.push (a);
        while (contagem < estudantes.size ()) {
            contagem += 1;
            if (sandwiches [i] == estudantes.front ()) {
                contagem = 0; // Reinicia a cobtagem
                i += 1;
                estudantes.pop ();
            } else {
                estudantes.push (estudantes.front ()); // Pega a frente e põe no final
                estudantes.pop (); // E rira de inde estava
            }
        }
        return estudantes.size ();
    }
};

