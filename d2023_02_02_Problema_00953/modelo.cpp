class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> seq;
        for (int i = 0; i < order.size (); i += 1)
            seq [order [i]] = i;
        function <int (string, string)> comp = [&seq] (string a, string b) {
            int i = 0, ib = 0;;
            while (i < a.size () && i < b.size ()) {
                if (a [i] == b [i]) {
                    i += 1;
                    continue;
                }
                if (seq [a [i]] < seq [b [i]])
                    return -1;
                // else
                return 1;
            }
            if (a.size () == b.size ())
                return 0;
            // else
            return a.size () < b.size ()? -1: 1;
        }; // function comp
        for (int i = 1; i < words.size (); i += 1)
            if (comp (words [i - 1], words [i]) == 1) // O segundo é posterior, lexicamemnte
                return false;
        return true; // Passou por todos e estavam em ordem
    }
};

