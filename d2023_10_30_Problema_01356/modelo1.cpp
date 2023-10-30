class Solution {
private:
    static int nBits (int i) {
        int resposta = 0;
        while (i > 0) {
            if ((i & 1) == 1)
                resposta += 1;
            i >>= 1;
        }
        return resposta;
    }
    static bool menor (int a, int b) {
        int ba = nBits (a);
        int bb = nBits (b);
        if (ba == bb)
            return a < b;
        // else
        return ba < bb;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort (arr.begin (), arr.end (), menor);
        return arr;
    }
};

