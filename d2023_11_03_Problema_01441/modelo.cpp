class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> resposta;
        int i = 0;
        int j = 1;
        const int t = target.size ();
        while (i < t) {
            resposta.push_back ("Push");
            if (target [i] != j)
                resposta.push_back ("Pop");
            else
                i += 1;
            j += 1;
        }
        return resposta;
    }
};

