class Solution {
public:
    string reversePrefix(string word, char ch) {
        int p = word.find (ch);
        if (p != string::npos) {
            int i = 0;
            int j = p;
            while (i < j)
                swap (word [i++], word [j--]);
        }
        return word;
    }
};

