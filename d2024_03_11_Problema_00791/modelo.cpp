class Solution {
public:
    string customSortString(string order, string s) {
        int atual = 0; // Posição da procura
        int encontrado = 0; // Para uso da localização
        int tamanho = s.length (); // Irá utilizar várias vezes
        std::string manter = s; // Só para não mexer no original
        char tmp; // Irá usar na permuta
        if (manter.length () > 0)
            for (string::iterator i = order.begin (); i != order.end (); i++)
                do {
                    if ((encontrado = manter.find (*i, atual)) != string::npos) {
                        tmp = manter [atual];
                        manter [atual] = manter [encontrado];
                        manter [encontrado] = tmp;
                        atual++;
                    } // if encontrado...
                } while ((atual < tamanho) && (encontrado != string::npos));
        return (manter);
    };
};

