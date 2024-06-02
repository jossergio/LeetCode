class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> contagem;
        for (int v: nums)
            contagem [v] += 1;
        vector<int> resposta;
        for (pair<int, int> item: contagem)
            if (item.second == 1)
                resposta.push_back (item.first);
        return resposta;
    }
};

