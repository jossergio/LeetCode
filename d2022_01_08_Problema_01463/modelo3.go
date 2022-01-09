
func pegar (grade [][] int, i int, j1 int, j2 int, acumulado int, maximo *int) {
    if i == len (grade) {
        if (acumulado) > *maximo {
            *maximo = acumulado
        }
        return // Não há mais o que fazer a partir daqui
    } // if i == len (grade)
    
    acumulado += grade [i][j1]
    if j1 != j2 {
        acumulado += grade [i][j2]
    }
    
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
                pegar (grade, i, jj1, jj2, acumulado, maximo)
            } // for jj2
        } // for jj1
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
            pegar (grade, i, jj1, jj2, acumulado, maximo)
        } // for jj2
    } // for jj1
    
} // pegar

func cherryPickup(grid [][]int) int {
    var maximo = 0
    pegar (grid, 0, 0, len (grid [0]) - 1, 0, &maximo)
    return maximo
}

