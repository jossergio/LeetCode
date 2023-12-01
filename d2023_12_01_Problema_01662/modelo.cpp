class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int pWord1 = 0;
        int pWord2 = 0;
        int pChar1 = 0;
        int pChar2 = 0;
        const int t1 = word1.size ();
        const int t2 = word2.size ();
        while (pWord1 < t1 && pWord2 < t2) {
            if (word1 [pWord1][pChar1++] != word2 [pWord2][pChar2++])
                return false;
            // else
            if (pChar1 == word1 [pWord1].size ()) {
                pChar1 = 0;
                pWord1 += 1;
            }
            if (pChar2 == word2 [pWord2].size ()) {
                pChar2 = 0;
                pWord2 += 1;
            }
        }
        return pWord1 == t1 && pWord2 == t2; // Os tamanhos dos vetores podem ser diferentes; só é verdadeiro se ambos passaram e chegaram ao final
    }
};

