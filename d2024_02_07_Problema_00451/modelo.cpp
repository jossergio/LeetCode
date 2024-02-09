class Solution {
private:
    static bool ordem (pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
public:
    string frequencySort(string s) {
        map<char, int> qtds;
        for (char c: s)
            qtds [c] += 1;
        priority_queue<pair<int, char>> fila;
        for (auto item: qtds)
            fila.push ({item.second, item.first});
        string resposta; // Vazia
        while (!fila.empty ()) {
            pair <int, char> item = fila.top ();
            resposta += string (item.first, item.second); // Ver sintaxe
            fila.pop ();
        }
        return resposta;
    }
};

