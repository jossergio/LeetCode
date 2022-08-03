class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        vector<int> tmp;
        
        for (vector<vector<int>>::iterator i = matrix.begin (); i != matrix.end (); i++)
            tmp.insert (tmp.end (), i->begin (), i->end ());
        
        sort (tmp.begin (), tmp.end ());
        
        return tmp [k - 1];
        
    }
};

