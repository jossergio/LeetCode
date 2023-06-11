class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters [letters.size () - 1])
            return letters [0]; // Para adiantar
        int pos = letters.size () - 1;
        while (pos >= 0 && letters [pos] > target)
            pos -= 1;
        return letters [pos + 1];
    }
};

