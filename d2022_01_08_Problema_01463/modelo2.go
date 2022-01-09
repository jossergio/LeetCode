
func pegar (grade [][] int, i int, j1 int, j2 int, max1 int, max2 int, maximo *int) {
    if i == len (grade) {
        if (max1 + max2) > *maximo {
            *maximo = max1 + max2
        }
        return // Não há mais o que fazer a partir daqui
    } // if i == len (grade)
    
    var tmp1 = grade [i][j1]
    grade [i][j1] = 0
    var tmp2 = grade [i][j2]
    grade [i][j2] = 0
    
    max1 += tmp1
    max2 += tmp2
    
    i++
    
    if j1 != j2 {
        for jj1 := j1 - 1; jj1 <= j1 + 1; jj1++ {
            if (jj1 < 0) || (jj1 >= len (grade [0])) {
                continue
            }
            for jj2 := j2 - 1; jj2 <= j2 + 1; jj2++ {
                if (jj2 < 0) || (jj2 >= len (grade [0])) {
                    continue
                }
                pegar (grade, i, jj1, jj2, max1, max2, maximo)
            } // for jj2
        } // for jj1
        i--
        grade [i][j2] = tmp2
        grade [i][j1] = tmp1
        return // Não precisa fazer mais nada
    } // if j1 != j2
    
    // A partir daqui, j1 == j2
    for jj1 := j1 - 1; jj1 <= j1; jj1++ {
        if (jj1 < 0) { // Não será maior
            continue
        }
        for jj2 := j2; jj2 <= j2 + 1; jj2++ {
            if (jj2 >= len (grade [0])) {
                continue
            }
            pegar (grade, i, jj1, jj2, max1, max2, maximo)
        } // for jj2
    } // for jj1
    
    // Nova iteração
    i--
    max1 -= tmp1
    max2 -= tmp2
    grade [i][j2] = tmp2
    grade [i][j1] = tmp1
    tmp2 = grade [i][j2]
    grade [i][j2] = 0
    tmp1 = grade [i][j1] // Ou seja, zero
    max1 += tmp1
    max2 += tmp2 // Para constar

    i++
    
    for jj1 := j1 - 1; jj1 <= j1; jj1++ {
        if (jj1 < 0) { // Não será maior
            continue
        }
        for jj2 := j2; jj2 <= j2 + 1; jj2++ {
            if (jj2 >= len (grade [0])) {
                continue
            }
            pegar (grade, i, jj1, jj2, max1, max2, maximo)
        } // for jj2
    } // for jj1

    i--
    grade [i][j1] = tmp1
    grade [i][j2] = tmp2
} // pegar

func cherryPickup(grid [][]int) int {
    var maximo = 0
    pegar (grid, 0, 0, len (grid [0]) - 1, 0, 0, &maximo)
    return maximo
}

