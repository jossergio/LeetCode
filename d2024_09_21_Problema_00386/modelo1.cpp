class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string, vector<string>, greater<string>> ordem;
        vector<int> resposta;
        resposta.reserve (n);
        while (n > 0) ordem.push (to_string (n--));
        while (!ordem.empty ()) {
            resposta.push_back (stoi (ordem.top ()));
            ordem.pop ();
        }
        return resposta;
    }
};

