func tirarZeros (s string) string {
    for len (s) > 1 && s [0] == '0' {
        s = s [1:]
    }
    
    return s
}

func multiply(num1 string, num2 string) string {
    
    // Variáveis auxiliares; definidas aqui para agilidade
    var vaiUm int // = 0
    var soma int // = 0
    var tmp int // = 0
    
    var acumulados [][] int
    
    valorNum := func (c byte) int {
        return int (c) - 48
    }
    
    caracterNum := func (v int) rune {
        return rune (v + 48)
    }
    
    for i2 := len (num2) - 1; i2 >= 0; i2-- {
        
        vaiUm = 0
        ordem := make ([] int, len (num2) - i2 - 1) // Preenchido com zeros
        
        for i1 := len (num1) - 1; i1 >= 0; i1-- {
            tmp = (valorNum (num1 [i1]) * valorNum (num2 [i2])) + vaiUm
            vaiUm = tmp / 10
            ordem = append (ordem, tmp % 10)
        }
        
        for vaiUm > 0 {
            ordem = append (ordem, (vaiUm % 10))
            vaiUm /= 10
        }
        
        for j := 0; j < len (acumulados); j++ { // Só para acrescentar zeros
            for len (acumulados [j]) < len (ordem) { // Até agora, é o maior, na ordem
                acumulados [j] = append (acumulados [j], 0)
            }
        }
        
        acumulados = append (acumulados, ordem)
    }
    
    var resposta string // = ""
    vaiUm = 0
    
    for j := 0; j < len (acumulados [0]); j++ {
        
        soma = vaiUm // Valor inicial
        
        for i := 0; i < len (acumulados); i++ {
            soma += (acumulados [i][j])
        }
        
        vaiUm = soma / 10
        resposta = string (caracterNum (soma % 10)) + resposta
    }
    
    for vaiUm > 0 {
        resposta = string (caracterNum (vaiUm % 10)) + resposta
        vaiUm /= 10
    }
    
    return tirarZeros (resposta)
}

