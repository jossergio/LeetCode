class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int contagem = 0; // Para ser utilizado para checar se a fila entrou em laço infinito
        queue<int> estudantes;
        stack<int> sandubas;
        for (int a: students)
            estudantes.push (a);
        for (int a = sandwiches.size () -1; a >= 0; a -= 1)
            sandubas.push (sandwiches [a]);
        while (contagem < estudantes.size ()) {
            contagem += 1;
            if (sandubas.top () == estudantes.front ()) {
                contagem = 0; // Reinicia a cobtagem
                sandubas.pop ();
                estudantes.pop ();
            } else {
                estudantes.push (estudantes.front ()); // Pega a frente e põe no final
                estudantes.pop (); // E rira de inde estava
            }
        }
        return estudantes.size ();
    }
};

