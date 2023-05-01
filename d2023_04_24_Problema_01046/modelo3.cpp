class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort (stones.begin (), stones.end ());
        while (stones.size () > 1) {
            int tmp = stones.back ();
            stones.pop_back ();
            tmp -= stones.back ();
            stones.pop_back ();
            if (tmp > 0) {
                stones.push_back (tmp);
                sort (stones.begin (), stones.end ());
            }
        }
        return (stones.size () > 0 ? stones [0] : 0);
    }
};

