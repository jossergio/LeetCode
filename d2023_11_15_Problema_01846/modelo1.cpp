class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>>  fila;
        for (int a: arr) {
            fila.push (a);
        }
        int ultimo = fila.top ();
        if (ultimo != 1)
            ultimo = 1;
        fila.pop ();
        while (!fila.empty ()) {
            int tmp = fila.top ();
            fila.pop ();
            ultimo = (tmp <= ultimo + 1 ? tmp : ultimo + 1);
        }
        return ultimo;
    }
};

