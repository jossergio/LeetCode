using meu_par = pair<double, vector<int>>;
class minha_ordem {
public:
    bool operator () (const meu_par& a, const meu_par& b) {
        return a.first > b.first;
    }
}; // minha_ordem
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        const int t = arr.size ();
        priority_queue<meu_par, vector<meu_par>, minha_ordem> fila;
        for (int i = 0; i < t; i += 1)
            for (int j = i + 1; j < t; j += 1) 
                fila.push ({(double) arr [i] / arr [j], vector<int> {arr [i], arr [j]}});
        while (k > 1) { // 1-begin
            fila.pop (); // Vai descartando os primeiros
            k -= 1;
        }
        return fila.top ().second;
    }
};

