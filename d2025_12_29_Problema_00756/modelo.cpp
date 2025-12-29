class Solution {
private:
    bool buscar (string& b, map<pair<char, char>, vector<char>>& p) {
        if (b.size () == 1) return true;
        // else
        return montar ("", b, p);
    }
    bool montar (string s, string b, map<pair<char, char>, vector<char>>& p) {
        if (s.size () == b.size () - 1) return buscar (s, p);
        // else
        size_t t = s.size ();
        pair<char, char> tmp = make_pair (b [t], b [t + 1]);
        if (p.count (tmp) == 0) return false;
        // else
        for (char c: p [tmp]) {
            if (montar (s + c, b, p)) return true;
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char, char>, vector<char>> pares;
        for (string a: allowed) pares [make_pair (a [0], a [1])].push_back (a [2]);
        return buscar (bottom, pares);
    }
};
