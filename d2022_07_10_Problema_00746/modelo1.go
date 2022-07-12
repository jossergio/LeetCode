func minimo (a int, b int) int {
    if a < b {
        return a
    }
    // else
    return b
}

func procurar (cost [] int, i int) int {
    
    if ! (i < len (cost)) { // Pode chegar maior
        return 0
    }
    
    return cost [i] + minimo (procurar (cost, i + 1), procurar (cost, i + 2))
}

func minCostClimbingStairs(cost []int) int {
    return minimo (procurar (cost, 0), procurar (cost, 1))
}

