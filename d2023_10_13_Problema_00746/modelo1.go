func minimo (a int, b int) int {
    if a < b {
        return a
    }
    // else
    return b
}

func minCostClimbingStairs(cost []int) int {
    
    f := make ([] int, len (cost))
    
    // Para agilizar e não precisar por um "se" dentro do laço
    // O problema cita que o tamanho mínimo é 2
    f [len (f) - 1] = cost [len (cost) - 1]
    f [len (f) - 2] = cost [len (cost) - 2]
    
    for i := len (cost) - 3; i >= 0; i-- {
        f [i] = cost [i] + minimo (f [i + 1], f [i + 2])
    }
    
    return minimo (f [0], f [1])
}

