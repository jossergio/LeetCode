bool ordem (int a, int b) {
    return to_string (a) < to_string (b);
}
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> resposta;
        resposta.reserve (n);
        while (n > 0) resposta.push_back (n--);
        sort (resposta.begin (), resposta.end (), ordem);
        return resposta;
    }
};

