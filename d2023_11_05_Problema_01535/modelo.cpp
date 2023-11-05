class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int t = arr.size ();
        queue<int> fila;
        for (int tmp: arr)
            fila.push (tmp);
        int vencedor = fila.front ();
        fila.pop ();
        int n = 0;
        while (n < k) {
            if (vencedor > fila.front ()) {
                n += 1;
                fila.push (fila.front ());
                fila.pop ();
            } else {
                n = 1;
                fila.push (vencedor); // Deixa de ser, nesse momento
                vencedor = fila.front ();
                fila.pop ();
            }
            if (n > t) // Iniciaria um laço desnecessário
                break;
        }
        return vencedor;
    }
};

