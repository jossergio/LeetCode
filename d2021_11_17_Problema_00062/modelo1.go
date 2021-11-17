var limiteM int
var limiteN int

func encontrar (i int, j int, total *int) {
    if (i == limiteM) && (j == limiteN) {
        *total += 1
    } else { // if (i == m) && (j == n)
        if i < limiteM {
            encontrar (i + 1, j, total)
        } // if i < limiteM
        if j < limiteN {
            encontrar (i, j + 1, total)
        } // if j < limiteN
    }
} // encontrar

func uniquePaths(m int, n int) int {
    var total int = 0
    limiteM = m
    limiteN = n
    encontrar (1, 1, &total)
    return total
}

