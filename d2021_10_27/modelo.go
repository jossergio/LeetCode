func sortColors(nums []int)  {
    var vermelho [] int
    var branco [] int
    var azul [] int
    for a := 0; a < len (nums); a++ {
        switch nums [a] {
            case 0: vermelho = append (vermelho, 0) // Já é o valor
            case 1: branco = append (branco, 1)
            case 2: azul = append (azul, 2)
        } // switch
    } // for a
    var retorno [] int
    retorno = append (retorno, vermelho...)
    retorno = append (retorno, branco...)
    retorno = append (retorno, azul...)
    copy (nums, retorno)
}

