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
        vector<pair<char, int>> lista;
        for (auto item: qtds)
            lista.push_back (item);
        sort (lista.begin (), lista.end (), ordem);
        string resposta; // Vazia
        for (auto a: lista)
            for (int qtd = 0; qtd < a.second; qtd++)
                resposta += a.first;
        return resposta;
    }
};

