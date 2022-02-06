func removeDuplicates(nums []int) int {
    
    // Alguns testes preliminares
    
    if len (nums) < 3 {
        return len (nums)
    }
    
    var contagem int = 0 // Quantos há iguais na sequência
    var anterior int = nums [0] // Inicialmente...
    var k int = 0 // Elemento que irá receber o próximo; também será o retorno
    
    for i := 0; i < len (nums); i++ {
        
        if nums [i] != anterior {
            contagem = 1 // Reinicia a contagem
            nums [k] = nums [i] // Pode ser o mesmo, se o vetor já ou ainda estiver correto
            anterior = nums [i]
            k++
        } else { // if nums [i] != anterior
            contagem++
            if contagem <= 2 {
                nums [k] = nums [i] // Pode...
                k++
            }
        } // else if nums [i] != anterior
        
    } // for i
    
    return k
}

