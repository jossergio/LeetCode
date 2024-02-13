class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mapa;
        const int limite = nums.size () / 2; // O limite é a metade da quantidade
        for (int n: nums) {
            mapa [n] += 1;
            if (mapa [n] > limite) {
                return n;
            }
        }
        return 0; // Só para ter algo; nunca chega aqui
    }
};

