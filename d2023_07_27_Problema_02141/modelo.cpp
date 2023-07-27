class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort (batteries.begin (), batteries.end ());
        long extra = 0;
        for (int i = 0; i < batteries.size () - n; i += 1)
            extra += batteries [i];
        vector<int> uso = vector (batteries.end () - n, batteries.end ());
        for (int i = 0; i < n - 1; i += 1) {
            if (extra < (long) ((i + 1) * (uso [i + 1] - uso [i])))
                return uso [i] + (extra / ((long) (i + 1)));
            extra -= (long) ((i + 1) * (uso [i + 1] - uso [i]));
        }
        return uso [n - 1] + (extra / n);
    }
};

