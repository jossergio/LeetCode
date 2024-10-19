class Solution {
private:
    string inverso (string t) {
        for (char& c: t) c = c == '1' ? '0' : '1';
        reverse (t.begin (), t.end ());
        return t;
    }
public:
    char findKthBit(int n, int k) {
        string s = "0"; // Já define o 1o
        while (s.size () < k) s += "1" + inverso (s);
        return s [k - 1]; // 0-begin
    }
};

