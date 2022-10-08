class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort (nums.begin (), nums.end ());
        for (int i = 0; i < nums.size () - 1; i++) // Notar que vai, até, o penúltimo
            if (nums [i] == nums [i + 1])
                return true;
        return false; // Por omissão
    }
};

