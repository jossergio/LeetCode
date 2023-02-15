func addToArrayForm(num []int, k int) []int {
    
    divmod10 := func (a int) (d int, r int) {
        d = a / 10
        r = a % 10
        return // d, r
    } // divmod10
    
    adicionar := func (a int, b int, vemUm int) (soma int, vaiUm int) {
        var tmp int = a + b + vemUm
        soma = (tmp % 10)
        vaiUm = (tmp / 10) % 10
        return // soma, vaiUm
    } // vaiUm
    
    igualar := func (n [] int, contagem int) (resposta [] int) {
        for contagem > 0 {
            resposta = append (resposta, 0)
            contagem -= 1
        }
        return append (resposta, n...)
    } // igualar
    
    var num2 [] int
    for k > 0 { // k nunca é zero; definição do problema
        divisao, resto := divmod10 (k)
        num2 = append ([] int {resto}, num2...) // Já monta invertendo
        k = divisao
    }
    
    if len (num) > len (num2) {
        num2 = igualar (num2, len (num) - len (num2))
    } else {
        if len (num2) > len (num) { // Sim. Irá dispensar o igual
            num = igualar (num, len (num2) - len (num))
        }
    }
    
    var vaiUm int // = 0
    var adicao int // = 0
    // adicao definida fora do laço
    var resposta [] int
    for i := len (num) - 1; i >= 0; i -= 1 {
        adicao, vaiUm = adicionar (num [i], num2 [i], vaiUm)
        resposta = append ([] int {adicao}, resposta...) // Já monta invertendo
    }
    if vaiUm == 1 { // Sobrou
        resposta = append ([] int {1}, resposta...) // Já joga na esquerda
    }
    return resposta // Vem com os dígitos invertidos
}

