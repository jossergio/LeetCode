class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs (fx - sx);
        int dy = abs (fy - sy);
        if (dx == 0 && dy == 0 && t > 0)
            return t > 1; // Pequeno ajuste
        // else
        return t >= max (dx, dy);
    }
};

