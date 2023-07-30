class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size ();
        vector dp (n, vector<int> (n, -1));
        function<int (int, int)> resolver = [&] (int esq, int dir) -> int {
            if (dp [esq][dir] == -1) {
                dp [esq][dir] = n;
                int j = -1;
                for (int i = esq; i < dir; i += 1) {
                    if (s [i] != s [dir] && j == -1)
                        j = i;
                    if (j != -1)
                        dp [esq][dir] = min (dp [esq][dir], 1 + resolver (j, i) + resolver (i + 1, dir));
                }
                if (j == -1)
                    dp [esq][dir] = 0;
            } // if dp == -1
            return dp [esq][dir];
        }; // resolver
        return 1 + resolver (0, n - 1);
    }
};

