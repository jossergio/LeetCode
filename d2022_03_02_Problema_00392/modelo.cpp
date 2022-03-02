class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i = 0; // Para s
        int j = 0; // para t
        int ts = s.length (); // Para s
        int tt = t.length (); // Para t
        
        while (i < ts && j < tt) {
            while (j < tt && s [i] != t [j])
                j++;
            if (j >= tt)
                return false;
            i++;
            j++;
        }
        
        return (i == ts);
    }
};

