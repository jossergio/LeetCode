class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> fila;
            for (int v: nums) fila.push (v);
            int r = 0;
            while (fila.size () >= 2 && fila.top () < k) {
                r += 1;
                int tmp = fila.top () * 2;
                fila.pop ();
                tmp += fila.top ();
                fila.pop ();
                fila.push (tmp);
            }
            return r;
        }
    };
    