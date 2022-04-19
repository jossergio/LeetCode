func mySqrt(x int) int {
    
    var resposta int = 1;
    
    for resposta * resposta <= x {
        resposta++
    }
    
    return resposta - 1
}

