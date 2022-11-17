func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
    var comumX1, comumX2, comumY1, comumY2 int // 0
    var comum bool = true // Se não houver, o andamento dirá
    if (bx1 >= ax1) && (bx1 < ax2) {
        comumX1 = bx1
    } else {
        if (ax1 >= bx1) && (ax1 < bx2) {
            comumX1 = ax1
        } else { // Não possuem coordenadas comuns
            comum = false
        }
    }
    if (ax2 > bx1) && (ax2 <= bx2) {
        comumX2 = ax2
    } else {
        if (bx2 > ax1) && (bx2 <= ax2) {
            comumX2 = bx2
        } else { // Idem
            comum = false
        }
    }
    if (ay1 >= by1) && (ay1 < by2) {
        comumY1 = ay1
    } else {
        if (by1 >= ay1) && (by1 < ay2) {
            comumY1 = by1
        } else { // Idem
            comum = false
        }
    }
    if (ay2 > by1) && (ay2 <= by2) {
        comumY2 = ay2
    } else {
        if (by2 > ay1) && (by2 <= ay2) {
            comumY2 = by2
        } else { // Idem
            comum = false
        }
    }
    var areaComum int // = 0
    if comum {
        areaComum = (comumX2 - comumX1) * (comumY2 - comumY1)
    }
    var area int // = 0
    area += (ax2 - ax1) * (ay2 - ay1)
    area += (bx2 - bx1) * (by2 - by1)
    // Separei os cálculos para melhor compreensão
    return area - areaComum
}

