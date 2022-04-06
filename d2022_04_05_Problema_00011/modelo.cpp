class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int resp = 0;
        int esq = 0;
        int dir = height.size () - 1;
        
        while (esq < dir) {
            resp = max (resp, min (height [esq], height [dir]) * (dir - esq));
            if (height [esq] < height [dir])
                esq++;
            else
                dir--;
        }
     return resp;
    }
};

