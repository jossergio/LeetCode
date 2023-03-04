class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size (); i += 1) {
            int j = 0;
            while (j < needle.size () && haystack [i + j] == needle [j])
                j += 1;
            if (j == needle.size ())
                return i;
        }
        return -1;
    }
};

