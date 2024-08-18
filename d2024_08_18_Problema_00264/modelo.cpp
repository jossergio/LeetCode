class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> fila;
        fila.push (1);
        long long ultimo = 0;
        while (n > 0) {
            long long tmp = fila.top ();
            fila.pop ();
            if (tmp > ultimo) {
                n -= 1;
                ultimo = tmp;
                fila.push (ultimo * 2);
                fila.push (ultimo * 3);
                fila.push (ultimo * 5);
            }
        }
        return static_cast<int> (ultimo);
    }
};

