const int modulo = 1000000007;

class Solution {
private:
    int rev (int n) {
        int r = 0;
        while (n > 0) {
            r *= 10; // Desloca
            r += n % 10;
            n /= 10;
        }
        return r;
    }
public:
    int countNicePairs(vector<int>& nums) {
        const int t = nums.size ();
        vector<int> sub (t, 0);
        int resposta = 0;
        for (int k = 0; k < t; k += 1)
            sub [k] = nums [k] - rev (nums [k]); // nums [i] - rev [i], se aparecer em j, serão pares
        unordered_map<int, int> mapa;
        for (int v: sub) {
            resposta = (resposta + mapa [v]) % modulo;
            mapa [v] += 1;
        }
        return resposta;
    }
};

