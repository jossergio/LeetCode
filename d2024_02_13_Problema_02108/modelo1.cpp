class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string w: words) {
            if (w == string (w.rbegin (), w.rend ()))
                return w;
        }
        return ""; // Não encontrou
    }
};

