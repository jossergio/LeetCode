class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> fila;
        long long total = 0;
        for (int g: gifts) {
            total += g;
            fila.push (g);
        }
        while (k > 0) {
            int p = fila.top ();
            fila.pop ();
            int raiz = floor (sqrt (p));
            total -= (p - raiz);
            fila.push (raiz);
            k -= 1;
        }
        return total;
    }
};

