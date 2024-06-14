class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int t = nums.size ();
        int ins = 0; // Inserção
        for (int c = 0; c < 3; c += 1) {

            while (ins < t) {
                while (ins < t && nums [ins] == c) {
                    ins += 1;
                }
                int p = ins + 1;
                while (p < t && nums [p] != c) {
                    p += 1;
                }
                if (p < t) {
                    swap (nums [ins], nums [p]);
                } else {
                    break; // Não há mais possibilidades nessa etapa
                }
            }
        }
    }
};

