class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int segComumX = min (ax2, bx2) - max (ax1, bx1); // Pode ficar negativo
        int segComumY = min (ay2, by2) - max (ay1, by1); // Idem
        int areaComum = (segComumX > 0 && segComumY > 0) ? segComumX * segComumY : 0;
        int area = (ax2 - ax1) * (ay2 - ay1);
        area += (bx2 - bx1) * (by2 - by1);
        // Separei os cálculos para melhor visualização
        return area - areaComum;
    }
};

