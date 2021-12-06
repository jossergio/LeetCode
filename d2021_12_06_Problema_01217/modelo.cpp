class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int par = 0, impar = 0;
        for (vector<int>::iterator p = position.begin (); p != position.end (); p++)
            if ((*p % 2) == 0)
                par++;
            else
                impar++;
        return ((par < impar) ? par : impar);
    }
};

