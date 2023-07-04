class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> qtds;
        for (int v: nums)
            qtds [v] +=1;
        for (auto i: qtds)
            if (i.second == 1)
                return i.first;
        return -1; // Não chega aqui
    }
};

