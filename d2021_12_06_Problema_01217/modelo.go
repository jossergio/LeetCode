func minCostToMoveChips(position []int) int {
    var pares int = 0
    var impares int = 0
    for _, p := range position {
        if p % 2 == 0 {
            pares++
        } else { // if p % 2 == 0
            impares++
        } // else if p % 2 == 0
    } // for range position
    if pares < impares {
        return pares // Que lógica, não?
    }
    return impares
}

