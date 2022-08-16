class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> listagem;
        
        for (auto c: s)
            listagem [c]++;
        
        for (int i = 0; i < s.size (); i++)
            if (listagem [s [i]] == 1)
                return i;

        return -1;
    }
};

