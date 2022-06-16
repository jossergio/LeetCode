var minimo int
var t [][] int

func menor (a int, b int) int {
    if a < b {
        return a
    }
    // else
    return b
}

func tratar (nivel int, indice int, acumulado int) {
    
    if nivel < len (t) {
        tratar (nivel + 1, indice, acumulado + t [nivel][indice])
        if (indice + 1) < len (t [nivel]) {
            tratar (nivel + 1, indice + 1, acumulado + t [nivel][indice + 1])
        }
    } else {
        minimo = menor (minimo, acumulado)
    }
}

func minimumTotal(triangle [][]int) int {
    
    minimo = math.MaxInt // Base
    
    // Cria global t
    t = make ([][] int, len (triangle))
    for i, v := range triangle {
        t [i] = v
    }
    
    tratar (0, 0, 0) // Base
    
    return minimo
}

