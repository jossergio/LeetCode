class Solution {
public:
    string makeGood(string s) {
        vector<char> fila;
        for (char c: s)
            if (fila.size () > 0 && abs (fila.back () - c) == 32)
                fila.pop_back ();
            else
                fila.push_back (c);
        return string (fila.begin (), fila.end ());
    }
};

