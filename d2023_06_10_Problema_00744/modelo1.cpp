class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int pos = 0;
        while (pos < letters.size () && letters [pos] <= target)
            pos += 1;
        if (pos == letters.size ())
            return letters [0];
        // else
        return letters [pos]; // Sempre passa, se houver
    }
};

