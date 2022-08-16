class Solution {
public:
    int firstUniqChar(string s) {
        
        int listagem [27] = {0};
        
        for (auto c: s)
            listagem [c - 97]++;
                
        for (int i = 0; i < s.size (); i++)
            if (listagem [s [i] - 97] == 1)
                return i;

        return -1;
    }
};

