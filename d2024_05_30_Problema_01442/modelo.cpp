class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int t = arr.size ();
        int resposta = 0;
        for (int i = 0; i < t; i += 1) {
            int base_i = 0;
            for (int z = i; z < t; z += 1) {
                base_i ^= arr [z];
                int base_j = 0;
                for (int j = z + 1; j < t; j += 1) {
                    base_j ^= arr [j];
                    if (base_i == base_j) {
                        resposta += 1;
                    }
                }
            }
        }
        return resposta;
    }
};

