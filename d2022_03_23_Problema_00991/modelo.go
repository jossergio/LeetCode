func brokenCalc(startValue int, target int) int {
    
    var resposta int // = 0
    
    for startValue < target {
        
        resposta++
        
        if target % 2 == 1 {
            target++
        } else {
            target /= 2
        }
    } // for
    
    return resposta + startValue - target // No final, target pode não ser o mesmo valor inicial
}

