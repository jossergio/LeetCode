class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string w: words) {
            auto p1 = w.begin ();
            auto p2 = w.rbegin ();
            int limite = (w.size () / 2) + (w.size () % 2);
            while (limite > 0) {
                if (*p1 != *p2)
                    break;
                limite -= 1;
                p1++;
                p2++;
            }
            if (limite == 0)
                return w;
        }
        return "";
    }
};

