class Solution {
public:
    string reversePrefix(string word, char ch) {
        int p = word.find (ch);
        if (p != string::npos)
            reverse (word.begin (), word.begin () + p + 1); // Exclusive
        return word;
    }
};

