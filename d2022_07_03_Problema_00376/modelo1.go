var numeros [] int // Para manter global e não ficar passando recursivamente

func maior (a int, b int) int {
    if a > b {
        return a
    }
    // else
    return b
}

func calcular (idx int, paraCima bool)  int {
    
    var maximo int // = 0
    
    for i := idx + 1; i < len (numeros); i++  {
        if (paraCima && numeros [i] > numeros [idx]) || (!paraCima && numeros [i] < numeros [idx]) {
            maximo = maior (maximo, 1 + calcular (i, !paraCima))
        }
    }
    
    return maximo
}

func wiggleMaxLength(nums []int) int {
    if len (nums) < 2 {
        return len (nums)
    }
    
    numeros = make ([] int, len (nums))
    
    copy (numeros, nums)
    
    return 1 + maior (calcular (0, true), calcular (0, false))
}

