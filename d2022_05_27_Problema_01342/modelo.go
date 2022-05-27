func numberOfSteps(num int) int {
    var contar int // = 0
    
    for num > 0 {
        if num % 2 == 1 {
            num--
        } else {
            num /= 2
        }
        contar++
    }
    
    return contar
}

