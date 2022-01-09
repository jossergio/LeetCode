
func pegarMaximo (a int, b int) int {
    if a > b {
        return a
    }
    return b
} // pegarMaximo

func pegar (grade [][] int, i int, j1 int, j2 int, acumulado int) (maximo int) {
    acumulado += grade [i][j1]
    if j1 != j2 {
        acumulado += grade [i][j2]
    }

    i++
    
    if i == len (grade) {
        return acumulado
    } // if i == len (grade)
    
    if j1 != j2 {
        for jj1 := j1 - 1; jj1 <= j1 + 1; jj1++ {
            if (jj1 < 0) || (jj1 >= len (grade [0])) {
                continue
            }
            for jj2 := j2 - 1; jj2 <= j2 + 1; jj2++ {
                if (jj2 < 0) || (jj2 >= len (grade [0])) {
                    continue
                }
                maximo = pegarMaximo (maximo, pegar (grade, i, jj1, jj2, acumulado))
            } // for jj2
        } // for jj1
    } else { // if j1 != j2
        for jj1 := j1 - 1; jj1 <= j1; jj1++ {
            if (jj1 < 0) { // Não será maior
                continue
            }
            for jj2 := j2; jj2 <= j2 + 1; jj2++ {
                if (jj2 >= len (grade [0])) {
                    continue
                }
                maximo = pegarMaximo (maximo, pegar (grade, i, jj1, jj2, acumulado))
            } // for jj2
        } // for jj1
    } // else if j1 != j2
    return // maximo
} // pegar

func cherryPickup(grid [][]int) int {
    return pegar (grid, 0, 0, len (grid [0]) - 1, 0)
}

