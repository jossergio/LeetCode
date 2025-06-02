func candy(ratings []int) int {
    
    maior := func (a int, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }
    
    doces := make ([] int, len (ratings))
    var i int // Será utilizada várias vezes
    
    
    for i = 0; i < len (doces); i++ {
        doces [i] = 1
    }
    
    for i = 1; i < len (ratings); i++ {
        if ratings [i] > ratings [i - 1] {
            doces [i] = doces [i - 1] + 1
        }
    }
    
    var soma int = doces [len (doces) - 1] // Nessa fase, o último conjunto não será modificado
    
    for i = len (ratings) - 2; i >= 0; i-- {
        
        if ratings [i] > ratings [i + 1] {
            doces [i] = maior (doces [i], doces [i + 1] + 1)
        }
        
        soma += doces [i]
    }
    
    return soma
}
