func plusOne(digits []int) []int {
    
    var vaiUm int = 1 // Pode ser
    
    for i := len (digits) - 1; vaiUm != 0 && i >= 0; i-- {
        digits [i] += vaiUm
        vaiUm = digits [i] / 10
        digits [i] %= 10
    }
    
    if vaiUm == 1 {
        digits = append ([] int {vaiUm}, digits...)
    }
    
    return digits
}

