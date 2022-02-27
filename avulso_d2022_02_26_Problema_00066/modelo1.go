func plusOne(digits []int) []int {
    
    var i int = len (digits) - 1
    
    digits [i] += 1
    
    var vaiUm int = digits [i] / 10
    digits [i] %= 10
    
    i--
    
    for vaiUm == 1 && i >= 0{
        digits [i] += vaiUm
        vaiUm = digits [i] / 10
        digits [i] %= 10
        i--
    }
    
    if vaiUm == 1 {
        resposta := [] int {vaiUm}
        return append (resposta, digits...)
    }
    
    return digits
}

