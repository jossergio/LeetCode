class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort (nums.begin (), nums.end ());
        int v = 0;
        int i = 0;
        const int t = nums.size ();
        while (i < t && v <= t - i) { // Permite sair antecipadamente, quando não houver mais possibilidades de encontrar
            if (v <= nums [i]) {
                if (v == t - i) { // 0-begin x 1-begin
                    return t - i;
                } else {
                    v += 1;
                }
            } else {
                i += 1;
            }
        }
        return -1;
    }
};v

