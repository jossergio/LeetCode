class Solution {
private:
    int paraMinutos (string t) {
        int p = t.find (':');
        int h = stoi (t.substr (0, p));
        int m = stoi (t.substr (p + 1));
        if (h == 0) h = 24;
        return 60 * h + m;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        const size_t t = timePoints.size ();
        vector<int> minutos;
        minutos.reserve (t);
        for (string s: timePoints) {
            minutos.push_back (paraMinutos (s));
        }
        sort (minutos.begin (), minutos.end ());
        int resposta = abs (minutos [t - 1] - 24 * 60 - minutos [0]); 
        for (int i = 1; i < t; i += 1) {
            resposta = min (resposta, minutos [i] - minutos [i - 1]);
        }
        return resposta;
    }
};

