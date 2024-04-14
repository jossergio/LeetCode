class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort (deck.begin (), deck.end ());
        deque<int> fila;
        fila.push_front (deck [deck.size () - 1]); // Joga o último a ser tirado
        int i = deck.size () - 2; // Inicia do penúltimo
        while (i >= 0) {
            fila.push_front (fila.back ());
            fila.pop_back ();
            fila.push_front (deck [i--]); // Inclui e já decrementa o índice
        }
        i = 0; // Reaproveita a variável
        while (!fila.empty ()) {
            deck [i++] = fila.front ();
            fila.pop_front ();
        }
        return deck;
    }
};

