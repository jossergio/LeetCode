class Solution {
public:
    int minOperations(vector<string>& logs) {
        int contador = 0;
        for (string s: logs) {
            if (s [0] == '.') { // Sempre há algo aqui
                if (s [1] == '.') { // É isso ou '/'
                    contador = max (contador - 1, 0);
                } // Senão, ou seja, é '/', permanece onde está
            } else {
                contador += 1;
            }
        }
        return contador;
    }
};

